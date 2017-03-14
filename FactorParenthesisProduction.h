#ifndef EXPRESSION_CALCULATOR_FACTORPARENTHESISPRODUCTION_H
#define EXPRESSION_CALCULATOR_FACTORPARENTHESISPRODUCTION_H

#include "Production.h"

class FactorParenthesisProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_FACTORPARENTHESISPRODUCTION_H
