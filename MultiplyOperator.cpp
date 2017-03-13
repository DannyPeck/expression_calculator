#include "MultiplyOperator.h"

MultiplyOperator::MultiplyOperator (void)
{
}

MultiplyOperator::~MultiplyOperator (void)
{
}

int MultiplyOperator::evaluate (int first, int second)
{
  return first * second;
}

void MultiplyOperator::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "*")
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}