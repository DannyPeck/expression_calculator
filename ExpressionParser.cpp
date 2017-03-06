#include <sstream>
#include <vector>
#include "ExpressionParser.h"
#include "Context.h"
#include "Start.h"

ExpressionParser::ExpressionParser (void)
: context_ (nullptr)
{
}

ExpressionParser::~ExpressionParser (void)
{
  delete this->context_;
}

int ExpressionParser::evaluate (std::string expression)
{
  std::vector<std::string> * tokens = new std::vector<std::string> ();
  std::stringstream input;
  input << expression;

  std::string token;
  while (!input.eof ())
  {
    input >> token;
    tokens->push_back (token);
  }

  this->context_ = new Context (tokens);
  std::stack<Symbol *> & symbols = this->context_->getSymbols ();
  Start * startSymbol = new Start ();
  symbols.push (startSymbol);
  while (this->context_->getBeginIterator () != this->context_->getEndIterator ())
  {
    std::string symbol = *this->context_->getBeginIterator ();

    if (symbol != "")
    {
      symbols.top ()->derive (*this->context_, symbol);
    }
    else
    {
      symbols.top ()->derive (*this->context_, "eof");
    }
  }

  int result = 0;
  try
  {
    result = startSymbol->evaluate ();
  }
  catch (std::exception & e)
  {
    delete startSymbol;
    delete this->context_;
    throw e;
  }

  delete startSymbol;
  delete this->context_;

  return result;
}