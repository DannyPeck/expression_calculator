#ifndef EXPRESSION_CALCULATOR_START_H
#define EXPRESSION_CALCULATOR_START_H

#include "Variable.h"

class Expression;

class Start : public Variable
{
  public:

    Start (void);

    ~Start (void);

    int evaluate (void);

    void derive (Context & context, std::string symbol);

  private:

    Expression * expression_;
};

#endif //EXPRESSION_CALCULATOR_START_H
