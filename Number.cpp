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

void Number::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (this->value_ == atoi (symbol.c_str ()))
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}