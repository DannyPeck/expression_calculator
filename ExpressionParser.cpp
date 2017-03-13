#include <sstream>
#include "ExpressionParser.h"
#include "ParseTree.h"
#include "Context.h"
#include "Start.h"
#include "DivideByZeroException.h"
#include "InvalidDerivationException.h"

ExpressionParser::ExpressionParser (void)
{
}

ExpressionParser::~ExpressionParser (void)
{
}

ParseTree * ExpressionParser::parse (const std::string & expression)
{
  std::vector<std::string> * tokens = new std::vector<std::string> ();
  std::stringstream input;
  input << expression;

  std::string token;
  while (!input.eof ())
  {
    input >> token;
    tokens->push_back (token);
  }

  return this->derive (tokens);
}

ParseTree * ExpressionParser::derive (std::vector<std::string> * tokens)
{
  Context * context = new Context (tokens);
  std::stack<Symbol *> & symbols = context->getSymbols ();
  Start * startSymbol = new Start ();
  symbols.push (startSymbol);

  while (context->hasNextToken ())
  {
    try
    {
      symbols.top ()->derive (*context);
    }
    catch (InvalidDerivationException & e)
    {
      delete context;
      delete startSymbol;
      throw e;
    }
  }

  delete context;

  return new ParseTree (startSymbol);
}