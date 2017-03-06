#include <iostream>
#include "Start.h"
#include "Expression.h"

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
  std::cout << "Start" << std::endl;
  return this->expression_->evaluate ();
}

void Start::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  std::cout << "Start, " << symbol << std::endl;
  if (symbol == "(")
  {
    symbols.pop ();
    this->expression_ = new Expression ();
    symbols.push (this->expression_);
  }
  else if (context.is_numeric (symbol))
  {
    std::cout << "S -> E; Number" << std::endl;
    std::cin.get ();
    symbols.pop ();
    this->expression_ = new Expression ();
    symbols.push (this->expression_);
    std::cin.get ();
  }
  else
  {
    throw invalid_production_exception ();
  }
}