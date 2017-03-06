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
  std::cout << "ETail" << std::endl;
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
  std::cout << "ETail, " << symbol << std::endl;
  if (symbol == ")")
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else if (symbol == "+")
  {
    std::cout << "ETail -> T ETail; +" << std::endl;
    std::cin.get ();
    symbols.pop ();
    this->operator_ = new AddOperator ();
    this->term_ = new Term ();
    this->expressionTail_ = new ExpressionTail ();
    symbols.push (this->expressionTail_);
    symbols.push (this->term_);
    context.nextSymbol ();
  }
  else if (symbol == "-")
  {
    symbols.pop ();
    this->operator_ = new SubtractOperator ();
    this->term_ = new Term ();
    this->expressionTail_ = new ExpressionTail ();
    symbols.push (this->expressionTail_);
    symbols.push (this->term_);
    context.nextSymbol ();
  }
  else if (symbol == "eof")
  {
    symbols.pop ();
  }
  else
  {
    throw invalid_production_exception ();
  }
}

BinaryOperator * ExpressionTail::getOperator (void)
{
  return this->operator_;
}
