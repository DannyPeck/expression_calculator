#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression (int precedence)
: left_operand_ (nullptr), right_operand_ (nullptr), precedence_ (precedence)
{
}

BinaryOperatorExpression::~BinaryOperatorExpression (void)
{
  delete this->left_operand_;
  delete this->right_operand_;
}