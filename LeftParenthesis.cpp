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

void LeftParenthesis::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "(")
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}