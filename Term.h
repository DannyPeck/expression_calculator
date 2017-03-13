#ifndef EXPRESSION_CALCULATOR_TERM_H
#define EXPRESSION_CALCULATOR_TERM_H

#include "Variable.h"

class Factor;
class TermTail;

class Term : public Variable
{
  public:

    Term (void);

    ~Term (void);

    int evaluate (void);

    void accept (SymbolVisitor & visitor);

    void setFactor (Factor * factor);

    void setTermTail (TermTail * termTail);

  private:

    Factor * factor_;

    TermTail * termTail_;
};

#endif //EXPRESSION_CALCULATOR_TERM_H
