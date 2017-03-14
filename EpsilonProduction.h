#ifndef EXPRESSION_CALCULATOR_EPSILONPRODUCTION_H
#define EXPRESSION_CALCULATOR_EPSILONPRODUCTION_H

#include "Production.h"

class EpsilonProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_EPSILONPRODUCTION_H
