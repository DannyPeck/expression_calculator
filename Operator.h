#ifndef EXPRESSION_CALCULATOR_OPERATOR_H
#define EXPRESSION_CALCULATOR_OPERATOR_H

#include "Terminal.h"

class Operator : public Terminal
{
  public:

    virtual ~Operator (void) = 0;

  protected:

    Operator (void);
};

#endif //EXPRESSION_CALCULATOR_OPERATOR_H
