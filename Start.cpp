#include "Start.h"
#include "Expression.h"
#include "LeftParenthesis.h"
#include "RightParenthesis.h"

Start::Start (void)
: expression_ (nullptr)
{
}

Start::~Start (void)
{
  delete this->expression_;
}

int Start::evaluate (void)
{
  return (this->expression_ != nullptr) ? this->expression_->evaluate () : 0;
}

void Start::accept (SymbolVisitor & visitor)
{
  visitor.visitStart (*this);
}

void Start::setExpression (Expression * expression)
{
  this->expression_ = expression;
}