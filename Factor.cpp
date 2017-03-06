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
    this->rightParenthesis_ = new RightParenthesis ();
    this->expression_ = new Expression ();
    this->leftParenthesis_ = new LeftParenthesis ();
    symbols.push (this->rightParenthesis_);
    symbols.push (this->expression_);
    symbols.push (this->leftParenthesis_);
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