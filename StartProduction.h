#ifndef EXPRESSION_CALCULATOR_STARTPRODUCTION_H
#define EXPRESSION_CALCULATOR_STARTPRODUCTION_H

#include "Production.h"

class StartProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_STARTPRODUCTION_H
