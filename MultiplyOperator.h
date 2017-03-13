#ifndef EXPRESSION_CALCULATOR_MULTIPLYOPERATOR_H
#define EXPRESSION_CALCULATOR_MULTIPLYOPERATOR_H

#include "BinaryOperator.h"

class MultiplyOperator : public BinaryOperator
{
  public:

    MultiplyOperator (void);

    ~MultiplyOperator (void);

    int evaluate (int first, int second);

    void accept (SymbolVisitor & visitor);
};

#endif //EXPRESSION_CALCULATOR_MULTIPLYOPERATOR_H
