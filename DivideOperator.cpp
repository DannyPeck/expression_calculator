#include "DivideOperator.h"
#include "DivideByZeroException.h"

int DivideOperator::evaluate (int first, int second)
{
  if (second != 0)
  {
    return first / second;
  }
  else
  {
    throw DivideByZeroException ();
  }
}

void DivideOperator::accept (SymbolVisitor & visitor)
{
  visitor.visitDivideOperator (*this);
}