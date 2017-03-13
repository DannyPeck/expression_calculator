#include "TermTail.h"
#include "Factor.h"
#include "BinaryOperator.h"
#include "DivideOperator.h"
#include "MultiplyOperator.h"
#include "DivideOperator.h"
#include "DivideByZeroException.h"

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
    try
    {
      result = op->evaluate (this->factor_->evaluate (), this->termTail_->evaluate ());
    }
    catch (std::exception & e)
    {
      delete op;
      throw DivideByZeroException ();
    }
  }
  else
  {
    result = this->factor_->evaluate ();
  }

  return result;
}

void TermTail::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
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
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    this->operator_ = new MultiplyOperator ();
    symbols.push (this->termTail_);
    symbols.push (this->factor_);
    symbols.push (this->operator_);
  }
  else if (token == "/")
  {
    symbols.pop ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    this->operator_ = new DivideOperator ();
    symbols.push (this->termTail_);
    symbols.push (this->factor_);
    symbols.push (this->operator_);
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