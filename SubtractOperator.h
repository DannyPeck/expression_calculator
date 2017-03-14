#ifndef EXPRESSION_CALCULATOR_SUBTRACTOPERATOR_H
#define EXPRESSION_CALCULATOR_SUBTRACTOPERATOR_H

#include "BinaryOperator.h"

class SubtractOperator : public BinaryOperator
{
  public:

    int evaluate (int first, int second);

    void accept (SymbolVisitor & visitor);
};

#endif //EXPRESSION_CALCULATOR_SUBTRACTOPERATOR_H
