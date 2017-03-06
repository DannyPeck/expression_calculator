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

void Expression::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "(")
  {
    symbols.pop ();
    this->term_ = new Term ();
    this->expressionTail_ = new ExpressionTail ();
    symbols.push (this->expressionTail_);
    symbols.push (this->term_);
  }
  else if (context.is_numeric (symbol))
  {
    symbols.pop ();
    this->term_ = new Term ();
    this->expressionTail_ = new ExpressionTail ();
    symbols.push (this->expressionTail_);
    symbols.push (this->term_);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}