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

void AddOperator::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "+")
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}