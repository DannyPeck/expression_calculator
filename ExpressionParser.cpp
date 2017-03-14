#include <sstream>
#include "ExpressionParser.h"
#include "ParseTree.h"
#include "DerivationVisitor.h"
#include "Context.h"
#include "Start.h"
#include "DivideByZeroException.h"
#include "InvalidDerivationException.h"

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

  DerivationVisitor * derivationVisitor = new DerivationVisitor (context);
  while (context->hasNextToken ())
  {
    Symbol * symbol = symbols.top ();
    try
    {
      symbol->accept (*derivationVisitor);
    }
    catch (InvalidDerivationException & e)
    {
      delete derivationVisitor;
      delete startSymbol;
      throw e;
    }
  }

  delete derivationVisitor;

  return new ParseTree (startSymbol);
}