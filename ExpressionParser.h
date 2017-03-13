#ifndef EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H
#define EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H

#include <string>

class Context;

class ExpressionParser
{
  public:

    ExpressionParser (void);

    ~ExpressionParser (void);

    int evaluate (const std::string & expression);

    void derive (Context & context);
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H
