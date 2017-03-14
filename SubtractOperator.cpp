#include "SubtractOperator.h"

int SubtractOperator::evaluate (int first, int second)
{
  return first - second;
}

void SubtractOperator::accept (SymbolVisitor & visitor)
{
  visitor.visitSubtractOperator (*this);
}