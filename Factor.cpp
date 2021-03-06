#include <stdlib.h>
#include "Factor.h"
#include "Expression.h"
#include "LeftParenthesis.h"
#include "RightParenthesis.h"
#include "Number.h"

Factor::Factor (void)
: leftParenthesis_ (nullptr), rightParenthesis_ (nullptr),
  expression_ (nullptr), number_ (nullptr)
{
}

Factor::~Factor (void)
{
  delete this->leftParenthesis_;
  delete this->rightParenthesis_;
  delete this->expression_;
  delete this->number_;
}

int Factor::evaluate (void)
{
  int result = 0;
  if (this->expression_ != nullptr)
  {
    result = this->expression_->evaluate ();
  }
  else if (this->number_ != nullptr)
  {
    result = this->number_->evaluate ();
  }

  return result;
}

void Factor::accept (SymbolVisitor & visitor)
{
  visitor.visitFactor (*this);
}

void Factor::setLeftParenthesis (LeftParenthesis * leftParenthesis)
{
  this->leftParenthesis_ = leftParenthesis;
}

void Factor::setExpression (Expression * expression)
{
  this->expression_ = expression;
}

void Factor::setRightParenthesis (RightParenthesis * rightParenthesis)
{
  this->rightParenthesis_ = rightParenthesis;
}

void Factor::setNumber (Number * number)
{
  this->number_ = number;
}