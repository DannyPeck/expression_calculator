#include "NumberExpression.h"

NumberExpression::NumberExpression (int value)
: value_ (value)
{
}

NumberExpression::~NumberExpression (void)
{
}

int NumberExpression::evaluate (void)
{
  return this->value_;
}