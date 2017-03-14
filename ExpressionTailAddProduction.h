#ifndef EXPRESSION_CALCULATOR_EXPRESSIONTAILADDPRODUCTION_H
#define EXPRESSION_CALCULATOR_EXPRESSIONTAILADDPRODUCTION_H

#include "Production.h"

class ExpressionTailAddProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONTAILADDPRODUCTION_H
