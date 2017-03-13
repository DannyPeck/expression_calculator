#ifndef EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H
#define EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H

#include "BinaryOperator.h"

class DivideOperator : public BinaryOperator
{
  public:

    DivideOperator (void);

    ~DivideOperator (void);

    int evaluate (int first, int second);

    void accept (SymbolVisitor & visitor);
};

#endif //EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H
