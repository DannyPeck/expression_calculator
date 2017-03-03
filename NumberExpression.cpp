#include "NumberExpression.h"

NumberExpression::NumberExpression (int value)
: value_ (value)
{
}

NumberExpression::~Expression ()
{
}

int NumberExpression::getValue ()
{
  return this->value_;
}