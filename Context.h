#ifndef EXPRESSION_CALCULATOR_CONTEXT_H
#define EXPRESSION_CALCULATOR_CONTEXT_H

#include <stack>
#include <string>
#include <vector>

class Symbol;

class Context
{
  public:

    Context (std::vector<std::string> * expression);

    ~Context (void);

    std::stack<Symbol *> & getSymbols (void);

    std::vector<std::string>::iterator & getBeginIterator (void);

    std::vector<std::string>::iterator & getEndIterator (void);

    std::vector<std::string> & getTokens (void);

    void nextSymbol (void);

    bool is_numeric (std::string token);

  private:

    std::vector<std::string> * tokens_;

    std::stack<Symbol *> * symbols_;

    std::vector<std::string>::iterator begin_;

    std::vector<std::string>::iterator end_;

};

#endif //EXPRESSION_CALCULATOR_CONTEXT_H
