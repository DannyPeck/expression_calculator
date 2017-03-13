#include "SubtractOperator.h"

SubtractOperator::SubtractOperator (void)
{
}

SubtractOperator::~SubtractOperator (void)
{
}

int SubtractOperator::evaluate (int first, int second)
{
  return first - second;
}

void SubtractOperator::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "-")
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}