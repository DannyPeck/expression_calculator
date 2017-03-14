#include "AddOperator.h"

int AddOperator::evaluate (int first, int second)
{
  return first + second;
}

void AddOperator::accept (SymbolVisitor & visitor)
{
  visitor.visitAddOperator (*this);
}