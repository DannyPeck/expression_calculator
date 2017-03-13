#ifndef EXPRESSION_CALCULATOR_START_H
#define EXPRESSION_CALCULATOR_START_H

#include "Variable.h"

class LeftParenthesis;
class Expression;

class Start : public Variable
{
  public:

    Start (void);

    ~Start (void);

    int evaluate (void);

    void derive (Context & context);

  private:

    LeftParenthesis * leftParenthesis_;

    Expression * expression_;
};

#endif //EXPRESSION_CALCULATOR_START_H
