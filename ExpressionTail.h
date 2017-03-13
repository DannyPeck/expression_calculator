#ifndef EXPRESSION_CALCULATOR_EXPRESSIONTAIL_H
#define EXPRESSION_CALCULATOR_EXPRESSIONTAIL_H

#include "Variable.h"

class Term;
class BinaryOperator;

class ExpressionTail : public Variable
{
  public:

    ExpressionTail (void);

    virtual ~ExpressionTail (void);

    virtual int evaluate (void);

    virtual void accept (SymbolVisitor & visitor);

    void setOperator (BinaryOperator * binaryOperator);

    void setTerm (Term * term);

    void setExpressionTail (ExpressionTail * expressionTail);

    BinaryOperator * getOperator (void);

  private:

    BinaryOperator * operator_;

    Term * term_;

    ExpressionTail * expressionTail_;
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONTAIL_H
