#include <stdlib.h>
#include "Context.h"
#include "Symbol.h"

Context::Context (std::vector<std::string> * tokens)
: tokens_ (tokens), symbols_ (new std::stack<Symbol *> ())
{
  this->begin_ = tokens_->begin ();
  this->end_ = tokens_->end ();
}

Context::~Context (void)
{
  delete this->symbols_;
  delete this->tokens_;
}

std::stack<Symbol *> & Context::getSymbols (void)
{
  return *this->symbols_;
}

std::vector<std::string>::iterator & Context::getBeginIterator (void)
{
  return this->begin_;
}

std::vector<std::string>::iterator & Context::getEndIterator (void)
{
  return this->end_;
}

std::vector<std::string> & Context::getTokens (void)
{
  return *this->tokens_;
}

void Context::nextSymbol (void)
{
  this->begin_ ++;
}

// checks for if the token has alpha and special characters
bool Context::is_numeric (std::string token)
{
  bool result = true;
  // scans the input token checking to see if any of the characters are not numeric
  for (int i = 0; i < token.length (); i++)
  {
    if (std::isalpha (token[i]) || std::ispunct (token[i]))
    {
      result = false;
    }
  }
  return result;
}