#include "NumberExpression.h"

NumberExpression::NumberExpression (int value)
: value_ (value)
{
}

NumberExpression::~Expression (void)
{
}

int NumberExpression::getValue (void)
{
  return this->value_;
}