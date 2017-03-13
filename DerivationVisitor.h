#ifndef EXPRESSION_CALCULATOR_DERIVATIONVISITOR_H
#define EXPRESSION_CALCULATOR_DERIVATIONVISITOR_H

#include "SymbolVisitor.h"

class Context;

class DerivationVisitor : public SymbolVisitor
{
  public:

    DerivationVisitor (Context * context);

    ~DerivationVisitor (void);

    void visitAddOperator (AddOperator & addOperator);

    void visitSubtractOperator (SubtractOperator & subtractOperator);

    void visitMultiplyOperator (MultiplyOperator & multiplyOperator);

    void visitDivideOperator (DivideOperator & divideOperator);

    void visitLeftParenthesis (LeftParenthesis & leftParenthesis);

    void visitRightParenthesis (RightParenthesis & rightParenthesis);

    void visitNumber (Number & number);

    void visitStart (Start & start);

    void visitExpression (Expression & expression);

    void visitExpressionTail (ExpressionTail & expressionTail);

    void visitTerm (Term & term);

    void visitTermTail (TermTail & termTail);

    void visitFactor (Factor & factor);

  private:

    Context * context_;
};

#endif //EXPRESSION_CALCULATOR_DERIVATIONVISITOR_H
