#ifndef EXPRESSION_CALCULATOR_SUBTRACTOPERATOR_H
#define EXPRESSION_CALCULATOR_SUBTRACTOPERATOR_H

#include "BinaryOperator.h"

class SubtractOperator : public BinaryOperator
{
  public:

    SubtractOperator (void);

    ~SubtractOperator (void);

    int evaluate (int first, int second);
};

#endif //EXPRESSION_CALCULATOR_SUBTRACTOPERATOR_H
