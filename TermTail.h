#ifndef EXPRESSION_CALCULATOR_TERMTAIL_H
#define EXPRESSION_CALCULATOR_TERMTAIL_H

#include "Variable.h"

class BinaryOperator;
class Factor;

class TermTail : public Variable
{
  public:

    TermTail (void);

    virtual ~TermTail (void);

    virtual int evaluate (void);

    virtual void derive (Context & context, std::string symbol);

    BinaryOperator * getOperator (void);

  protected:

    BinaryOperator * operator_;

    Factor * factor_;

    TermTail * termTail_;
};

#endif //EXPRESSION_CALCULATOR_TERMTAIL_H
