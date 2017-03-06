#ifndef EXPRESSION_CALCULATOR_FACTOR_H
#define EXPRESSION_CALCULATOR_FACTOR_H

#include "Variable.h"

class Expression;
class Number;

class Factor : public Variable
{
  public:

    Factor (void);

    virtual ~Factor (void);

    virtual int evaluate (void);

    virtual void derive (Context & context, std::string symbol);

  protected:

    Expression * expression_;

    Number * number_;
};

#endif //EXPRESSION_CALCULATOR_FACTOR_H
