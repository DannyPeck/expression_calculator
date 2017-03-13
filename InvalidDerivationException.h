#ifndef EXPRESSION_CALCULATOR_INVALIDDERIVATIONEXCEPTION_H
#define EXPRESSION_CALCULATOR_INVALIDDERIVATIONEXCEPTION_H

#include <stdexcept>

class InvalidDerivationException : public std::exception
{
  public:
    // Default constructor
    InvalidDerivationException (void) : std::exception ()
    {
    }

    virtual const char * what () const throw ()
    {
      return "Invalid expression";
    }
};

#endif //EXPRESSION_CALCULATOR_INVALIDDERIVATIONEXCEPTION_H
