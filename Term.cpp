#include "Term.h"
#include "BinaryOperator.h"
#include "Factor.h"
#include "TermTail.h"

Term::Term (void)
: factor_ (nullptr), termTail_ (nullptr)
{
}

Term::~Term (void)
{
  delete this->factor_;
  delete this->termTail_;
}

int Term::evaluate (void)
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

void Term::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "(")
  {
    symbols.pop ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    symbols.push (termTail_);
    symbols.push (factor_);
  }
  else if (context.is_numeric (token))
  {
    symbols.pop ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    symbols.push (termTail_);
    symbols.push (factor_);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}