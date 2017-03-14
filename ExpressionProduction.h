#ifndef EXPRESSION_CALCULATOR_EXPRESSIONPRODUCTION_H
#define EXPRESSION_CALCULATOR_EXPRESSIONPRODUCTION_H

#include "Production.h"

class ExpressionProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONPRODUCTION_H
