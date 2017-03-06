#include <iostream>
#include "Number.h"

Number::Number (int value)
: value_ (value)
{
}

Number::~Number (void)
{
}

int Number::evaluate (void)
{
  std::cout << "Number" << std::endl;
  return this->value_;
}

void Number::derive (Context & context, std::string symbol)
{
}