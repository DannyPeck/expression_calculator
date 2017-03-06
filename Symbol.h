#ifndef EXPRESSION_CALCULATOR_SYMBOL_H
#define EXPRESSION_CALCULATOR_SYMBOL_H

#include <string>
#include <stdexcept>
#include <stack>
#include "Context.h"

class Symbol
{
  public:

    virtual ~Symbol (void) = 0;

    virtual int evaluate (void) = 0;

    virtual void derive (Context & context, std::string symbol) = 0;

  protected:

    Symbol (void);

    class invalid_production_exception : public std::exception
    {
      public:
        // Default constructor
        invalid_production_exception (void) : std::exception ()
        {
        }

        virtual const char * what () const throw ()
        {
          return "Invalid expression";
        }
    };
};

#endif //EXPRESSION_CALCULATOR_SYMBOL_H