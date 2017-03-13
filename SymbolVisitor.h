#ifndef EXPRESSION_CALCULATOR_SYMBOLVISITOR_H
#define EXPRESSION_CALCULATOR_SYMBOLVISITOR_H

class AddOperator;
class SubtractOperator;
class MultiplyOperator;
class DivideOperator;
class LeftParenthesis;
class RightParenthesis;
class Number;
class Start;
class Expression;
class ExpressionTail;
class Term;
class TermTail;
class Factor;

class SymbolVisitor
{
  public:

    virtual ~SymbolVisitor (void) = 0;

    virtual void visitAddOperator (AddOperator & addOperator) = 0;

    virtual void visitSubtractOperator (SubtractOperator & subtractOperator) = 0;

    virtual void visitMultiplyOperator (MultiplyOperator & multiplyOperator) = 0;

    virtual void visitDivideOperator (DivideOperator & divideOperator) = 0;

    virtual void visitLeftParenthesis (LeftParenthesis & leftParenthesis) = 0;

    virtual void visitRightParenthesis (RightParenthesis & rightParenthesis) = 0;

    virtual void visitNumber (Number & number) = 0;

    virtual void visitStart (Start & start) = 0;

    virtual void visitExpression (Expression & expression) = 0;

    virtual void visitExpressionTail (ExpressionTail & expressionTail) = 0;

    virtual void visitTerm (Term & term) = 0;

    virtual void visitTermTail (TermTail & termTail) = 0;

    virtual void visitFactor (Factor & factor) = 0;

  protected:

    SymbolVisitor (void);
};

#endif //EXPRESSION_CALCULATOR_SYMBOLVISITOR_H
