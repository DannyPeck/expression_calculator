#include "DivideOperator.h"

DivideOperator::DivideOperator (void)
{
}

DivideOperator::~DivideOperator (void)
{
}

int DivideOperator::evaluate (int first, int second)
{
  if (second != 0)
  {
    return first / second;
  }
  else
  {
    throw divide_by_zero_exception ();
  }
}