#ifndef EXPRESSION_CALCULATOR_TERMTAILDIVIDEPRODUCTION_H
#define EXPRESSION_CALCULATOR_TERMTAILDIVIDEPRODUCTION_H

#include "Production.h"

class TermTailDivideProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_TERMTAILDIVIDEPRODUCTION_H
