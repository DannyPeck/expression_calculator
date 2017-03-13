#ifndef EXPRESSION_CALCULATOR_ADDOPERATOR_H
#define EXPRESSION_CALCULATOR_ADDOPERATOR_H

#include "BinaryOperator.h"

class AddOperator : public BinaryOperator
{
  public:

    AddOperator (void);

    ~AddOperator (void);

    int evaluate (int first, int second);

    void accept (SymbolVisitor & visitor);
};

#endif //EXPRESSION_CALCULATOR_ADDOPERATOR_H
