#include <iostream>
#include "Start.h"
#include "Expression.h"
#include "LeftParenthesis.h"

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
  return this->expression_->evaluate ();
}

void Start::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "(")
  {
    symbols.pop ();
    this->expression_ = new Expression ();
    LeftParenthesis * leftParenthesis = new LeftParenthesis ();
    symbols.push (leftParenthesis);
    symbols.push (this->expression_);
  }
  else if (context.is_numeric (symbol))
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