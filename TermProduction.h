#ifndef EXPRESSION_CALCULATOR_TERMPRODUCTION_H
#define EXPRESSION_CALCULATOR_TERMPRODUCTION_H

#include "Production.h"

class TermProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_TERMPRODUCTION_H
