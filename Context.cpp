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

std::stack<Symbol *> & Context::getSymbols (void) const
{
  return *this->symbols_;
}

const std::string & Context::getToken (void) const
{
  return *this->begin_;
}

void Context::nextToken (void)
{
  ++ this->begin_;
}

bool Context::hasNextToken (void) const
{
  return this->begin_ != this->end_;
}

// checks for if the token has alpha and special characters
bool Context::is_numeric (const std::string & token) const
{
  bool result = true;
  // scans the input token checking to see if any of the characters are not numeric
  for (std::string::const_iterator iter = token.begin (); iter != token.end (); ++ iter)
  {
    char character = *iter;
    if (std::isalpha (character) || std::ispunct (character))
    {
      result = false;
    }
  }
  return result;
}