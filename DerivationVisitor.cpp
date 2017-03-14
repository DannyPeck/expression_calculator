#include <stack>
#include <cstdlib>
#include <vector>
#include "DerivationVisitor.h"
#include "InvalidDerivationException.h"
#include "Context.h"
#include "Symbol.h"
#include "AddOperator.h"
#include "SubtractOperator.h"
#include "MultiplyOperator.h"
#include "DivideOperator.h"
#include "LeftParenthesis.h"
#include "RightParenthesis.h"
#include "Number.h"
#include "Start.h"
#include "Expression.h"
#include "ExpressionTail.h"
#include "Term.h"
#include "TermTail.h"
#include "Factor.h"

DerivationVisitor::DerivationVisitor (Context * context)
: context_ (context)
{

}

DerivationVisitor::~DerivationVisitor (void)
{
  delete this->context_;
}

void DerivationVisitor::visitAddOperator (AddOperator & addOperator)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "+")
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitSubtractOperator (SubtractOperator & subtractOperator)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "-")
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitMultiplyOperator (MultiplyOperator & multiplyOperator)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "*")
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitDivideOperator (DivideOperator & divideOperator)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "/")
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitLeftParenthesis (LeftParenthesis & leftParenthesis)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "(")
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitRightParenthesis (RightParenthesis & rightParenthesis)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == ")")
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitNumber (Number & number)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (number.getValue () == atoi (token.c_str ()))
  {
    symbols.pop ();
    this->context_->nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitStart (Start & start)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "(")
  {
    symbols.pop ();
    Expression * expression = new Expression ();
    LeftParenthesis * leftParenthesis = new LeftParenthesis ();
    start.setExpression (expression);
    start.setLeftParenthesis (leftParenthesis);
    symbols.push (leftParenthesis);
    symbols.push (expression);
  }
  else if (this->context_->is_numeric (token))
  {
    symbols.pop ();
    Expression * expression = new Expression ();
    start.setExpression (expression);
    symbols.push (expression);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitExpression (Expression & expression)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "(")
  {
    symbols.pop ();
    Term * term = new Term ();
    ExpressionTail * expressionTail = new ExpressionTail ();
    expression.setTerm (term);
    expression.setExpressionTail (expressionTail);
    symbols.push (expressionTail);
    symbols.push (term);
  }
  else if (this->context_->is_numeric (token))
  {
    symbols.pop ();
    Term * term = new Term ();
    ExpressionTail * expressionTail = new ExpressionTail ();
    expression.setTerm (term);
    expression.setExpressionTail (expressionTail);
    symbols.push (expressionTail);
    symbols.push (term);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitExpressionTail (ExpressionTail & expressionTail)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == ")")
  {
    symbols.pop ();
  }
  else if (token == "+")
  {
    symbols.pop ();
    Term * term = new Term ();
    ExpressionTail * tail = new ExpressionTail ();
    AddOperator * addOperator = new AddOperator ();
    expressionTail.setTerm (term);
    expressionTail.setExpressionTail (tail);
    expressionTail.setOperator (addOperator);
    symbols.push (tail);
    symbols.push (term);
    symbols.push (addOperator);
  }
  else if (token == "-")
  {
    symbols.pop ();
    Term * term = new Term ();
    ExpressionTail * exprTail = new ExpressionTail ();
    SubtractOperator * subtractOperator = new SubtractOperator ();
    expressionTail.setTerm (term);
    expressionTail.setExpressionTail (exprTail);
    expressionTail.setOperator (subtractOperator);
    symbols.push (exprTail);
    symbols.push (term);
    symbols.push (subtractOperator);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitTerm (Term & term)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "(")
  {
    symbols.pop ();
    Factor * factor = new Factor ();
    TermTail * termTail = new TermTail ();
    term.setFactor (factor);
    term.setTermTail (termTail);
    symbols.push (termTail);
    symbols.push (factor);
  }
  else if (this->context_->is_numeric (token))
  {
    symbols.pop ();
    Factor * factor = new Factor ();
    TermTail * termTail = new TermTail ();
    term.setFactor (factor);
    term.setTermTail (termTail);
    symbols.push (termTail);
    symbols.push (factor);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitTermTail (TermTail & termTail)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == ")")
  {
    symbols.pop ();
  }
  else if (token == "+")
  {
    symbols.pop ();
  }
  else if (token == "-")
  {
    symbols.pop ();
  }
  else if (token == "*")
  {
    symbols.pop ();
    TermTail * tail = new TermTail ();
    Factor * factor = new Factor ();
    MultiplyOperator * multiplyOperator = new MultiplyOperator ();
    termTail.setTermTail (tail);
    termTail.setFactor (factor);
    termTail.setOperator (multiplyOperator);
    symbols.push (tail);
    symbols.push (factor);
    symbols.push (multiplyOperator);
  }
  else if (token == "/")
  {
    symbols.pop ();
    TermTail * tail = new TermTail ();
    Factor * factor = new Factor ();
    DivideOperator * divideOperator = new DivideOperator ();
    termTail.setTermTail (tail);
    termTail.setFactor (factor);
    termTail.setOperator (divideOperator);
    symbols.push (tail);
    symbols.push (factor);
    symbols.push (divideOperator);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

void DerivationVisitor::visitFactor (Factor & factor)
{
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  const std::string & token = this->context_->getToken ();
  if (token == "(")
  {
    symbols.pop ();
    RightParenthesis * rightParenthesis = new RightParenthesis ();
    Expression * expression = new Expression ();
    LeftParenthesis * leftParenthesis = new LeftParenthesis ();
    factor.setRightParenthesis (rightParenthesis);
    factor.setExpression (expression);
    factor.setLeftParenthesis (leftParenthesis);
    symbols.push (rightParenthesis);
    symbols.push (expression);
    symbols.push (leftParenthesis);
  }
  else if (this->context_->is_numeric (token))
  {
    symbols.pop ();
    Number * number = new Number (atoi (token.c_str ()));
    factor.setNumber (number);
    symbols.push (number);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}