#include <stdlib.h>
#include "Number.h"

Number::Number (int value)
: value_ (value)
{
}

Number::~Number (void)
{
}

int Number::evaluate (void)
{
  return this->value_;
}

void Number::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (this->value_ == atoi (token.c_str ()))
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}