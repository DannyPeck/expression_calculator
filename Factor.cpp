#include <iostream>
#include <stdlib.h>
#include "Factor.h"
#include "Expression.h"
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
  std::cout << "Factor" << std::endl;
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
  std::cout << "Factor, " << symbol << std::endl;
  if (symbol == "(")
  {
    symbols.pop ();
    this->expression_ = new Expression ();
    symbols.push (this->expression_);
    context.nextSymbol ();
  }
  else if (context.is_numeric (symbol))
  {
    std::cout << "F -> Number; Number" << std::endl;
    std::cin.get ();
    symbols.pop ();
    this->number_ = new Number (atoi (symbol.c_str ()));
    context.nextSymbol ();
  }
  else
  {
    throw invalid_production_exception ();
  }
}