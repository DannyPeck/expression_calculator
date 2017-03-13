#include "SubtractOperator.h"

SubtractOperator::SubtractOperator (void)
{
}

SubtractOperator::~SubtractOperator (void)
{
}

int SubtractOperator::evaluate (int first, int second)
{
  return first - second;
}

void SubtractOperator::accept (SymbolVisitor & visitor)
{
  visitor.visitSubtractOperator (*this);
}