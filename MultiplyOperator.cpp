#include "MultiplyOperator.h"

MultiplyOperator::MultiplyOperator (void)
{
}

MultiplyOperator::~MultiplyOperator (void)
{
}

int MultiplyOperator::evaluate (int first, int second)
{
  return first * second;
}

void MultiplyOperator::accept (SymbolVisitor & visitor)
{
  visitor.visitMultiplyOperator (*this);
}