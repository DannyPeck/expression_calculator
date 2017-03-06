#ifndef EXPRESSION_CALCULATOR_DIVIDEBYZEROEXCEPTION_H
#define EXPRESSION_CALCULATOR_DIVIDEBYZEROEXCEPTION_H

#include <stdexcept>

class DivideByZeroException : public std::exception
{
  public:
    // Default constructor
    DivideByZeroException (void) : std::exception ()
    {
    }

    virtual const char * what () const throw ()
    {
      return "Cannot divide by 0";
    }
};

#endif //EXPRESSION_CALCULATOR_DIVIDEBYZEROEXCEPTION_H
