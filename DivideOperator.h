#ifndef EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H
#define EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H

#include "BinaryOperator.h"

class DivideOperator : public BinaryOperator
{
  public:

    DivideOperator (void);

    ~DivideOperator (void);

    int evaluate (int first, int second);

    void derive (Context & context, std::string symbol);
};

#endif //EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H
