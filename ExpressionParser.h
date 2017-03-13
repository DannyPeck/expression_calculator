#ifndef EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H
#define EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H

#include <string>
#include <vector>

class Context;
class ParseTree;

class ExpressionParser
{
  public:

    ExpressionParser (void);

    ~ExpressionParser (void);

    ParseTree * parse (const std::string & expression);

  private:

    ParseTree * derive (std::vector<std::string> * tokens);
};

#endif //EXPRESSION_CALCULATOR_EXPRESSIONPARSER_H
