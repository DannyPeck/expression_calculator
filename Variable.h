#ifndef EXPRESSION_CALCULATOR_VARIABLE_H
#define EXPRESSION_CALCULATOR_VARIABLE_H

#include "Symbol.h"

class Variable : public Symbol
{
  public:

    virtual ~Variable (void) = 0;

    int evaluate (void) = 0;

    void derive (Context & context, std::string symbol) = 0;

  protected:

    Variable (void);
};

#endif //EXPRESSION_CALCULATOR_VARIABLE_H
