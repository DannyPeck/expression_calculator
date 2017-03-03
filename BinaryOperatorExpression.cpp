#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression (Expression * left_operand, Expression * right_operand, BinaryOperator * op)
: left_operand_ (left_operand), right_operand_ (right_operand), operator_ (op)
{
}

BinaryOperatorExpression::~BinaryOperatorExpression (void)
{
  delete this->left_operand_;
  delete this->right_operand_;
  delete this->operator_;
}

int BinaryOperatorExpression::evaluate (void)
{
  return this->operator_->evaluate (this->left_operand_, this->right_operand_);
}