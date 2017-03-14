#ifndef EXPRESSION_CALCULATOR_EXPRESSIONTAILSUBTRACTPRODUCTION_H
#define EXPRESSION_CALCULATOR_EXPRESSIONTAILSUBTRACTPRODUCTION_H

#include "Production.h"

class ExpressionTailSubtractProduction : public Production
{
  public:

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONTAILSUBTRACTPRODUCTION_H
