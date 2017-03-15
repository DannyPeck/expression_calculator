#include "ExpressionTail.h"
#include "Term.h"
#include "Expression.h"
#include "BinaryOperator.h"
#include "AddOperator.h"
#include "SubtractOperator.h"

ExpressionTail::ExpressionTail (void)
: operator_ (nullptr), term_ (nullptr), expressionTail_ (nullptr)
{
}

ExpressionTail::~ExpressionTail (void)
{
  delete this->operator_;
  delete this->term_;
  delete this->expressionTail_;
}

int ExpressionTail::evaluate (void)
{
  int result = 0;
  if (this->term_ != nullptr)
  {
    if (this->expressionTail_ != nullptr)
    {
      BinaryOperator * op = this->expressionTail_->getOperator ();
      if (op != nullptr)
      {
        result = op->evaluate (this->term_->evaluate (), this->expressionTail_->evaluate ());
      }
      else
      {
        result = this->term_->evaluate ();
      }
    }
    else
    {
      result = this->term_->evaluate ();
    }
  }

  return result;
}

void ExpressionTail::accept (SymbolVisitor & visitor)
{
  visitor.visitExpressionTail (*this);
}

void ExpressionTail::setOperator (BinaryOperator * binaryOperator)
{
  this->operator_ = binaryOperator;
}

void ExpressionTail::setTerm (Term * term)
{
  this->term_ = term;
}

void ExpressionTail::setExpressionTail (ExpressionTail * expressionTail)
{
  this->expressionTail_ = expressionTail;
}

BinaryOperator * ExpressionTail::getOperator (void)
{
  return this->operator_;
}
