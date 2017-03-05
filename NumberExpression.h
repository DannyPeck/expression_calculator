#ifndef EXPRESSION_CALCULATOR_NUMBEREXPRESSION_H
#define EXPRESSION_CALCULATOR_NUMBEREXPRESSION_H

#include "Expression.h"

class NumberExpression : public Expression
{
  public:

    NumberExpression (int value);

    ~NumberExpression (void);

    int evaluate (void);

  private:

    int value_;
};

#endif //EXPRESSION_CALCULATOR_NUMBEREXPRESSION_H
