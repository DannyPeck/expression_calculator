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

void LeftParenthesis::accept (SymbolVisitor & visitor)
{
  visitor.visitLeftParenthesis (*this);
}