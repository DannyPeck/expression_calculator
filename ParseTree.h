#ifndef EXPRESSION_CALCULATOR_PARSETREE_H
#define EXPRESSION_CALCULATOR_PARSETREE_H

#include "Symbol.h"

class ParseTree
{
  public:

    ParseTree (Symbol * root);

    ~ParseTree (void);

    int evaluate (void);

  private:

    Symbol * root_;
};

#endif //EXPRESSION_CALCULATOR_PARSETREE_H
