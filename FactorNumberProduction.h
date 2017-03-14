#ifndef EXPRESSION_CALCULATOR_FACTORNUMBERPRODUCTION_H
#define EXPRESSION_CALCULATOR_FACTORNUMBERPRODUCTION_H

#include "Production.h"

class FactorNumberProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_FACTORNUMBERPRODUCTION_H
