#ifndef EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H
#define EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression
{
  public:

    BinaryOperatorExpression (Expression * left_operand, Expression * right_operand, BinaryOperator * op);

    ~BinaryOperatorExpression (void);

    int evaluate (void);

  private:

    Expression * left_operand_;

    Expression * right_operand_;

    BinaryOperator * operator_;
};

#endif //EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H
