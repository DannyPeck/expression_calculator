#ifndef EXPRESSION_CALCULATOR_RIGHTPARENTHESIS_H
#define EXPRESSION_CALCULATOR_RIGHTPARENTHESIS_H

#include "Terminal.h"

class RightParenthesis : public Terminal
{
  public:

    RightParenthesis (void);

    ~RightParenthesis (void);

    int evaluate (void);

    void accept (SymbolVisitor & visitor);
};

#endif //EXPRESSION_CALCULATOR_RIGHTPARENTHESIS_H
