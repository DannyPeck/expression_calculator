#ifndef EXPRESSION_CALCULATOR_BINARYOPERATOR_H
#define EXPRESSION_CALCULATOR_BINARYOPERATOR_H

#include "Operator.h"

class BinaryOperator : public Operator
{
  public:

    virtual int evaluate (int first, int second) = 0;

  private:

    virtual int evaluate (void);
};

#endif //EXPRESSION_CALCULATOR_BINARYOPERATOR_H
