#ifndef EXPRESSION_CALCULATOR_TERMTAILMULTIPLYPRODUCTION_H
#define EXPRESSION_CALCULATOR_TERMTAILMULTIPLYPRODUCTION_H

#include "Production.h"

class TermTailMultiplyProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_TERMTAILMULTIPLYPRODUCTION_H
