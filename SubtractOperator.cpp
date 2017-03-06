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

void SubtractOperator::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "-")
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}