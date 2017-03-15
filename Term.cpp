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
  if (this->factor_ != nullptr)
  {
    if (this->termTail_ != nullptr)
    {
      BinaryOperator * op = this->termTail_->getOperator ();
      if (op != nullptr)
      {
        result = op->evaluate (this->factor_->evaluate (), this->termTail_->evaluate ());
      }
      else
      {
        result = this->factor_->evaluate ();
      }
    }
    else
    {
      result = this->factor_->evaluate ();
    }
  }

  return result;
}

void Term::accept (SymbolVisitor & visitor)
{
  visitor.visitTerm (*this);
}

void Term::setFactor (Factor * factor)
{
  this->factor_ = factor;
}

void Term::setTermTail (TermTail * termTail)
{
  this->termTail_ = termTail;
}