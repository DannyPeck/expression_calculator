#include <iostream>
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
  std::cout << "Term" << std::endl;
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

void Term::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  std::cout << "Term, " << symbol << std::endl;
  if (symbol == "(")
  {
    symbols.pop ();
    this->factor_ = new Factor ();
    this->termTail_ = new TermTail ();
    symbols.push (termTail_);
    symbols.push (factor_);
  }
  else if (context.is_numeric (symbol))
  {
    std::cout << "T -> F TTail; Number" << std::endl;
    std::cin.get ();
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