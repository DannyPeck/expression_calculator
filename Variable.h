#ifndef EXPRESSION_CALCULATOR_VARIABLE_H
#define EXPRESSION_CALCULATOR_VARIABLE_H

#include "Symbol.h"

class Variable : public Symbol
{
  public:

    virtual ~Variable (void) = 0;
};

#endif //EXPRESSION_CALCULATOR_VARIABLE_H
