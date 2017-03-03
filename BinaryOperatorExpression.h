#ifndef EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H
#define EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression
{
  public:

    BinaryOperatorExpression (void);

    ~BinaryOperatorExpression (void);

  private:

    Expression * left_operand_;

    Expression * right_operand_;

    BinaryOperatorExpression operator_;

};

#endif //EXPRESSION_CALCULATOR_BINARYOPERATOREXPRESSION_H
