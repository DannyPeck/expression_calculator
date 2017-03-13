#include "Expression.h"
#include "Term.h"
#include "ExpressionTail.h"
#include "BinaryOperator.h"

Expression::Expression (void)
: term_ (nullptr), expressionTail_ (nullptr)
{
}

Expression::~Expression (void)
{
  delete this->term_;
  delete this->expressionTail_;
}

int Expression::evaluate (void)
{
  int result = 0;
  BinaryOperator * op = this->expressionTail_->getOperator ();
  if (op != nullptr)
  {
    result = op->evaluate (this->term_->evaluate (), this->expressionTail_->evaluate ());
  }
  else
  {
    result = this->term_->evaluate ();
  }

  return result;
}

void Expression::accept (SymbolVisitor & visitor)
{
  visitor.visitExpression (*this);
}

void Expression::setTerm (Term * term)
{
  this->term_ = term;
}

void Expression::setExpressionTail (ExpressionTail * expressionTail)
{
  this->expressionTail_ = expressionTail;
}