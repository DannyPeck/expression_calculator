#include "MultiplyOperator.h"

int MultiplyOperator::evaluate (int first, int second)
{
  return first * second;
}

void MultiplyOperator::accept (SymbolVisitor & visitor)
{
  visitor.visitMultiplyOperator (*this);
}