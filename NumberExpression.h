#ifndef EXPRESSION_CALCULATOR_NUMBEREXPRESSION_H
#define EXPRESSION_CALCULATOR_NUMBEREXPRESSION_H

#include "Expression.h"

class NumberExpression : Expression
{
  public:

    NumberExpression (int value);

    int getValue (void);

  private:

    int value_;
};

#endif //EXPRESSION_CALCULATOR_NUMBEREXPRESSION_H
