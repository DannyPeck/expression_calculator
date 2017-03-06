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

void MultiplyOperator::derive (Context & context, std::string symbol)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  if (symbol == "*")
  {
    symbols.pop ();
    context.nextSymbol ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}