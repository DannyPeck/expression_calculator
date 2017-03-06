#ifndef EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H
#define EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H

#include <stdexcept>
#include "BinaryOperator.h"

class DivideOperator : public BinaryOperator
{
  public:

    DivideOperator (void);

    ~DivideOperator (void);

    int evaluate (int first, int second);

  private:

    class divide_by_zero_exception : public std::exception
    {
      public:
        // Default constructor
        divide_by_zero_exception (void) : std::exception ()
        {
        }

        virtual const char * what () const throw ()
        {
          return "Cannot divide by 0";
        }
    };
};

#endif //EXPRESSION_CALCULATOR_DIVIDEOPERATOR_H
