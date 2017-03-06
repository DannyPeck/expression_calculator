#ifndef EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H
#define EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H

#include <string>

class Context;

class ExpressionParser
{
  public:

    ExpressionParser (void);

    ~ExpressionParser (void);

    int evaluate (std::string expression);

  private:

    Context * context_;
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H
