#ifndef EXPRESSION_CALCULATOR_START_H
#define EXPRESSION_CALCULATOR_START_H

#include "Variable.h"

class LeftParenthesis;
class RightParenthesis;
class Expression;

class Start : public Variable
{
  public:

    Start (void);

    ~Start (void);

    int evaluate (void);

    void accept (SymbolVisitor & visitor);

    void setExpression (Expression * expression);

  private:

    Expression * expression_;
};

#endif //EXPRESSION_CALCULATOR_START_H
