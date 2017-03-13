#ifndef EXPRESSION_CALCULATOR_FACTOR_H
#define EXPRESSION_CALCULATOR_FACTOR_H

#include "Variable.h"

class LeftParenthesis;
class RightParenthesis;
class Expression;
class Number;

class Factor : public Variable
{
  public:

    Factor (void);

    virtual ~Factor (void);

    virtual int evaluate (void);

    virtual void accept (SymbolVisitor & visitor);

    void setLeftParenthesis (LeftParenthesis * leftParenthesis);

    void setExpression (Expression * expression);

    void setRightParenthesis (RightParenthesis * rightParenthesis);

    void setNumber (Number * number);

  protected:

    LeftParenthesis * leftParenthesis_;

    Expression * expression_;

    RightParenthesis * rightParenthesis_;

    Number * number_;
};

#endif //EXPRESSION_CALCULATOR_FACTOR_H
