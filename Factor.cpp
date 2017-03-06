#include <iostream>
#include <stdlib.h>
#include "Factor.h"
#include "Expression.h"
#include "LeftParenthesis.h"
#include "RightParenthesis.h"
#include "Number.h"

Factor::Factor (void)
: expression_ (nullptr), number_ (nullptr)
{
}

Factor::~Factor (void)
{
  delete this->expression_;
  delete this->number_;
}

int Factor::evaluate (void)
{
  if (this->expression_ != nullptr)
  {
    return this->expression_->evaluate ();
  }
  else
  {
    return this->number_->evaluate ();
  }
}

void Factor::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "(")
  {
    symbols.pop ();
    RightParenthesis * rightParenthesis = new RightParenthesis ();
    this->expression_ = new Expression ();
    LeftParenthesis * leftParenthesis = new LeftParenthesis ();
    symbols.push (rightParenthesis);
    symbols.push (this->expression_);
    symbols.push (leftParenthesis);
  }
  else if (context.is_numeric (symbol))
  {
    symbols.pop ();
    this->number_ = new Number (atoi (symbol.c_str ()));
    symbols.push (this->number_);
  }
  else
  {
    throw InvalidDerivationException ();
  }
}