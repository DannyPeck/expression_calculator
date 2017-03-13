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

void RightParenthesis::accept (SymbolVisitor & visitor)
{
  visitor.visitRightParenthesis (*this);
}