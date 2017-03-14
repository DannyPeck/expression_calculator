#ifndef EXPRESSION_CALCULATOR_PRODUCTION_H
#define EXPRESSION_CALCULATOR_PRODUCTION_H

class Context;

class Production
{
  public:

    virtual void derive (Context & context) = 0;
};

#endif //EXPRESSION_CALCULATOR_PRODUCTION_H
