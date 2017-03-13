#include <sstream>
#include <vector>
#include "ExpressionParser.h"
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

int ExpressionParser::evaluate (const std::string & expression)
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

  Context * context = new Context (tokens);

  std::stack<Symbol *> & symbols = context->getSymbols ();
  Start * startSymbol = new Start ();
  symbols.push (startSymbol);

  this->derive (*context);

  int result = 0;
  try
  {
    result = startSymbol->evaluate ();
  }
  catch (std::exception & e)
  {
    delete startSymbol;
    throw DivideByZeroException ();
  }

  delete startSymbol;

  return result;
}

void ExpressionParser::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  while (context.hasNextToken ())
  {
    symbols.top ()->derive (context);
  }
}