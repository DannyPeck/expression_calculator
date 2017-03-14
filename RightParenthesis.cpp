#include "RightParenthesis.h"

int RightParenthesis::evaluate (void)
{
  return 0;
}

void RightParenthesis::accept (SymbolVisitor & visitor)
{
  visitor.visitRightParenthesis (*this);
}