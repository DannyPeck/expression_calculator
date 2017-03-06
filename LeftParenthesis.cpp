#include "LeftParenthesis.h"

LeftParenthesis::LeftParenthesis (void)
{
}

LeftParenthesis::~LeftParenthesis (void)
{
}

int LeftParenthesis::evaluate (void)
{
  return 0;
}

void LeftParenthesis::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "(")
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}