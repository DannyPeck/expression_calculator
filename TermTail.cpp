#include <iostream>
#include "TermTail.h"
#include "Factor.h"
#include "BinaryOperator.h"
#include "DivideOperator.h"
#include "MultiplyOperator.h"
#include "DivideOperator.h"

TermTail::TermTail (void)
: operator_ (nullptr), factor_ (nullptr), termTail_ (nullptr)
{
}

TermTail::~TermTail (void)
{
  delete this->operator_;
  delete this->factor_;
  delete this->termTail_;
}

int TermTail::evaluate (void)
{
  int result = 0;
  BinaryOperator * op = this->termTail_->getOperator ();
  if (op != nullptr)
  {
    result = op->evaluate (this->factor_->evaluate (), this->termTail_->evaluate ());
  }
  else
  {
    result = this->factor_->evaluate ();
  }

  return result;
}

void TermTail::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == ")")
  {
    symbols.pop ();
  }
  else if (symbol == "+")
  {
    symbols.pop ();
  }
  else if (symbol == "-")
  {
    symbols.pop ();
  }
  else if (symbol == "*")
  {
    symbols.pop ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    this->operator_ = new MultiplyOperator ();
    symbols.push (this->termTail_);
    symbols.push (this->factor_);
    symbols.push (this->operator_);
  }
  else if (symbol == "/")
  {
    symbols.pop ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    this->operator_ = new DivideOperator ();
    symbols.push (this->termTail_);
    symbols.push (this->factor_);
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

BinaryOperator * TermTail::getOperator (void)
{
  return this->operator_;
}