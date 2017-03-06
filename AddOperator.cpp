#include "AddOperator.h"

AddOperator::AddOperator (void)
{
}

AddOperator::~AddOperator (void)
{
}

int AddOperator::evaluate (int first, int second)
{
  return first + second;
}

void AddOperator::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "+")
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}