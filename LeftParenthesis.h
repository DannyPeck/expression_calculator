#ifndef EXPRESSION_CALCULATOR_LEFTPARENTHESIS_H
#define EXPRESSION_CALCULATOR_LEFTPARENTHESIS_H

#include "Terminal.h"

class LeftParenthesis : public Terminal
{
  public:

    int evaluate (void);

    void accept (SymbolVisitor & visitor);
};

#endif //EXPRESSION_CALCULATOR_LEFTPARENTHESIS_H
