#ifndef EXPRESSION_CALCULATOR_NUMBER_H
#define EXPRESSION_CALCULATOR_NUMBER_H

#include "Terminal.h"

class Number : public Terminal
{
  public:

    Number (int value);

    ~Number (void);

    int evaluate (void);

    void derive (Context & context, std::string symbol);

  private:

    int value_;
};

#endif //EXPRESSION_CALCULATOR_NUMBER_H
