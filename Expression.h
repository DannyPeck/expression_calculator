#ifndef EXPRESSION_CALCULATOR_EXPRESSION_H
#define EXPRESSION_CALCULATOR_EXPRESSION_H

class Expression
{
  public:

    // destructor
    virtual ~Expression (void) = 0;

    // returns result of expression
    virtual int evaluate (void) = 0;

  protected:

    // prevents instantiation
    Expression (void);
};

#endif //EXPRESSION_CALCULATOR_EXPRESSION_H
