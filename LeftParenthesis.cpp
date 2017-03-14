#include "LeftParenthesis.h"

int LeftParenthesis::evaluate (void)
{
  return 0;
}

void LeftParenthesis::accept (SymbolVisitor & visitor)
{
  visitor.visitLeftParenthesis (*this);
}