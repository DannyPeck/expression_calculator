#ifndef EXPRESSION_CALCULATOR_CONTEXT_H
#define EXPRESSION_CALCULATOR_CONTEXT_H

#include <stack>
#include <string>
#include <vector>

class Symbol;

class Context
{
  public:

    Context (std::vector<std::string> * tokens);

    ~Context (void);

    std::stack<Symbol *> & getSymbols (void) const;

    const std::string & getToken (void) const;

    void nextToken (void);

    bool hasNextToken (void) const;

    bool is_numeric (const std::string & token) const;

  private:

    std::vector<std::string> * tokens_;

    std::stack<Symbol *> * symbols_;

    std::vector<std::string>::const_iterator begin_;

    std::vector<std::string>::const_iterator end_;

};

#endif //EXPRESSION_CALCULATOR_CONTEXT_H
