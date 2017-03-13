#ifndef EXPRESSION_CALCULATOR_EXPRESSION_H
#define EXPRESSION_CALCULATOR_EXPRESSION_H

#include "Variable.h"

class Term;
class ExpressionTail;

class Expression : public Variable
{
  public:

    Expression (void);

    ~Expression (void);

    int evaluate (void);

    void accept (SymbolVisitor & visitor);

    void setTerm (Term * term);

    void setExpressionTail (ExpressionTail * expressionTail);

  private:

    Term * term_;

    ExpressionTail * expressionTail_;
};

#endif //EXPRESSION_CALCULATOR_EXPRESSION_H
