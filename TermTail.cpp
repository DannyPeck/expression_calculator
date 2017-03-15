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
  if (this->factor_ != nullptr)
  {
    if (this->termTail_ != nullptr)
    {
      BinaryOperator * op = this->termTail_->getOperator ();
      if (op != nullptr)
      {
        try
        {
          result = op->evaluate (this->factor_->evaluate (), this->termTail_->evaluate ());
        }
        catch (DivideByZeroException & e)
        {
          delete op;
          throw e;
        }
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

void TermTail::accept (SymbolVisitor & visitor)
{
  visitor.visitTermTail (*this);
}

void TermTail::setOperator (BinaryOperator * binaryOperator)
{
  this->operator_ = binaryOperator;
}

void TermTail::setFactor (Factor * factor)
{
  this->factor_ = factor;
}

void TermTail::setTermTail (TermTail * termTail)
{
  this->termTail_ = termTail;
}

BinaryOperator * TermTail::getOperator (void)
{
  return this->operator_;
}