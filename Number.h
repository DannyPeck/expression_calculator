#ifndef EXPRESSION_CALCULATOR_NUMBER_H
#define EXPRESSION_CALCULATOR_NUMBER_H

#include "Terminal.h"

class Number : public Terminal
{
  public:

    Number (int value);

    int evaluate (void);

    void accept (SymbolVisitor & visitor);

    const int getValue (void) const;

  private:

    int value_;
};

#endif //EXPRESSION_CALCULATOR_NUMBER_H
