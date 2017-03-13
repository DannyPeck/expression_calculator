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

void Start::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "(")
  {
    symbols.pop ();
    this->expression_ = new Expression ();
    this->leftParenthesis_ = new LeftParenthesis ();
    symbols.push (this->leftParenthesis_);
    symbols.push (this->expression_);
  }
  else if (context.is_numeric (token))
  {
    symbols.pop ();
    this->expression_ = new Expression ();
    symbols.push (this->expression_);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}