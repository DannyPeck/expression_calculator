#ifndef EXPRESSION_CALCULATOR_TERMINAL_H
#define EXPRESSION_CALCULATOR_TERMINAL_H

#include "Symbol.h"

class Terminal : public Symbol
{
  public:

    virtual ~Terminal (void) = 0;

  protected:

    Terminal (void);
};

#endif //EXPRESSION_CALCULATOR_TERMINAL_H
