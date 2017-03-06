#include <iostream>
#include "TermTail.h"
#include "Factor.h"
#include "BinaryOperator.h"
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
  std::cout << "TermTail" << std::endl;
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
  std::cout << "TermTail, " << symbol << std::endl;
  if (symbol == ")")
  {
    symbols.pop ();
    context.nextSymbol ();
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
    this->operator_ = new MultiplyOperator ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    symbols.push (this->termTail_);
    symbols.push (this->factor_);
    context.nextSymbol ();
  }
  else if (symbol == "/")
  {
    symbols.pop ();
    this->operator_ = new DivideOperator ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    symbols.push (this->termTail_);
    symbols.push (this->factor_);
    context.nextSymbol ();
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