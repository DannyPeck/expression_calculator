#ifndef EXPRESSION_CALCULATOR_LEFTPARENTHESIS_H
#define EXPRESSION_CALCULATOR_LEFTPARENTHESIS_H

#include "Terminal.h"

class LeftParenthesis : public Terminal
{
  public:

    LeftParenthesis (void);

    ~LeftParenthesis (void);

    int evaluate (void);

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_LEFTPARENTHESIS_H
