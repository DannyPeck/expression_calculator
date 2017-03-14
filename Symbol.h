#ifndef EXPRESSION_CALCULATOR_SYMBOL_H
#define EXPRESSION_CALCULATOR_SYMBOL_H

#include "SymbolVisitor.h"

class Symbol
{
  public:

    virtual ~Symbol (void) = 0;

    virtual int evaluate (void) = 0;

    virtual void accept (SymbolVisitor & visitor) = 0;
};

#endif //EXPRESSION_CALCULATOR_SYMBOL_H
