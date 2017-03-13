#include "DivideOperator.h"
#include "DivideByZeroException.h"

DivideOperator::DivideOperator (void)
{
}

DivideOperator::~DivideOperator (void)
{
}

int DivideOperator::evaluate (int first, int second)
{
  if (second != 0)
  {
    return first / second;
  }
  else
  {
    throw DivideByZeroException ();
  }
}

void DivideOperator::derive (Context & context)
{
  std::stack<Symbol *> & symbols = context.getSymbols ();
  const std::string & token = context.getToken ();
  if (token == "/")
  {
    symbols.pop ();
    context.nextToken ();
  }
  else
  {
    throw InvalidDerivationException ();
  }
}