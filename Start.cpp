#include "Start.h"
#include "Expression.h"
#include "LeftParenthesis.h"

Start::Start (void)
: leftParenthesis_ (nullptr), expression_ (nullptr)
{
}

Start::~Start (void)
{
  delete this->leftParenthesis_;
  delete this->expression_;
}

int Start::evaluate (void)
{
  return this->expression_->evaluate ();
}

void Start::accept (SymbolVisitor & visitor)
{
  visitor.visitStart (*this);
}

void Start::setLeftParenthesis (LeftParenthesis * leftParenthesis)
{
  this->leftParenthesis_ = leftParenthesis;
}

void Start::setExpression (Expression * expression)
{
  this->expression_ = expression;
}