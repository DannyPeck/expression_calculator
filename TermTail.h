#ifndef EXPRESSION_CALCULATOR_TERMTAIL_H
#define EXPRESSION_CALCULATOR_TERMTAIL_H

#include "Variable.h"

class BinaryOperator;
class Factor;

class TermTail : public Variable
{
  public:

    TermTail (void);

    ~TermTail (void);

    int evaluate (void);

    void accept (SymbolVisitor & visitor);

    void setOperator (BinaryOperator * binaryOperator);

    void setFactor (Factor * factor);

    void setTermTail (TermTail * termTail);

    BinaryOperator * getOperator (void);

  protected:

    BinaryOperator * operator_;

    Factor * factor_;

    TermTail * termTail_;
};

#endif //EXPRESSION_CALCULATOR_TERMTAIL_H
