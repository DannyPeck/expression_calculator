#include <iostream>
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

void ExpressionTail::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == ")")
  {
    symbols.pop ();
  }
  else if (symbol == "+")
  {
    symbols.pop ();
    this->term_ = new Term ();
    this->expressionTail_ = new ExpressionTail ();
    this->operator_ = new AddOperator ();
    symbols.push (this->expressionTail_);
    symbols.push (this->term_);
    symbols.push (this->operator_);
  }
  else if (symbol == "-")
  {
    symbols.pop ();
    this->term_ = new Term ();
    this->expressionTail_ = new ExpressionTail ();
    this->operator_ = new SubtractOperator ();
    symbols.push (this->expressionTail_);
    symbols.push (this->term_);
    symbols.push (this->operator_);
  }
  else if (symbol == "eof")
  {
    symbols.pop ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}

BinaryOperator * ExpressionTail::getOperator (void)
{
  return this->operator_;
}
