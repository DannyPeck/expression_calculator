#ifndef EXPRESSION_CALCULATOR_RIGHTPARENTHESIS_H
#define EXPRESSION_CALCULATOR_RIGHTPARENTHESIS_H

#include "Terminal.h"

class RightParenthesis : public Terminal
{
  public:

    RightParenthesis (void);

    ~RightParenthesis (void);

    int evaluate (void);

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_RIGHTPARENTHESIS_H
