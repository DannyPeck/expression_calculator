#ifndef EXPRESSION_CALCULATOR_BINARYOPERATOR_H
#define EXPRESSION_CALCULATOR_BINARYOPERATOR_H

#include "Operator.h"

class BinaryOperator : public Operator
{
  public:

    virtual ~BinaryOperator (void) = 0;

    virtual int evaluate (int first, int second) = 0;

  protected:

    BinaryOperator (void);
};

#endif //EXPRESSION_CALCULATOR_BINARYOPERATOR_H
