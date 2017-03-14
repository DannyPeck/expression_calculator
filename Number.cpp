#include <stdlib.h>
#include "Number.h"

Number::Number (int value)
: value_ (value)
{
}

int Number::evaluate (void)
{
  return this->value_;
}

void Number::accept (SymbolVisitor & visitor)
{
  visitor.visitNumber (*this);
}

const int Number::getValue (void) const
{
  return this->value_;
}