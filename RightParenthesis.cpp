#include "RightParenthesis.h"

RightParenthesis::RightParenthesis (void)
{
}

RightParenthesis::~RightParenthesis (void)
{
}

int RightParenthesis::evaluate (void)
{
  return 0;
}

void RightParenthesis::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == ")")
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}