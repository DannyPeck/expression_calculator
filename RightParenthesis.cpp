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

void RightParenthesis::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == ")")
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}