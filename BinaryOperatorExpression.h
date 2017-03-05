#ifndef EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H
#define EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression
{
  public:

    BinaryOperatorExpression (int precedence);

    virtual ~BinaryOperatorExpression (void);

    virtual int evaluate (void) = 0;

    virtual void setLeftOperand (Expression * left_operand) = 0;

    virtual void setRightOperand (Expression * right_operand) = 0;

    virtual int getPrecedence (void) = 0;

  protected:

    Expression * left_operand_;

    Expression * right_operand_;

    int precedence_;
};

#endif //EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H
