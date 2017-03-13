#ifndef EXPRESSION_CALCULATOR_SYMBOL_H
#define EXPRESSION_CALCULATOR_SYMBOL_H

#include <string>
#include <stdexcept>
#include <stack>
#include "Context.h"
#include "InvalidDerivationException.h"

class Symbol
{
  public:

    virtual ~Symbol (void) = 0;

    virtual int evaluate (void) = 0;

    virtual void derive (Context & context) = 0;

  protected:

    Symbol (void);
};

#endif //EXPRESSION_CALCULATOR_SYMBOL_H
