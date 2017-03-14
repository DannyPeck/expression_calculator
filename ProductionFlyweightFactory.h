#ifndef EXPRESSION_CALCULATOR_PRODUCTIONFLYWEIGHTFACTORY_H
#define EXPRESSION_CALCULATOR_PRODUCTIONFLYWEIGHTFACTORY_H

#include "ProductionFactory.h"

class ProductionFlyweightFactory : public ProductionFactory
{
  public:

    ProductionFlyweightFactory (void);

    ~ProductionFlyweightFactory (void);

    StartProduction * createStartProduction (void);

    ExpressionProduction * createExpressionProduction (void);

    ExpressionTailAddProduction * createExpressionTailAddProduction (void);

    ExpressionTailSubtractProduction * createExpressionTailSubtractProduction (void);

    EpsilonProduction * createEpsilonProduction (void);

    TermProduction * createTermProduction (void);

    TermTailMultiplyProduction * createTermTailMultiplyProduction (void);

    TermTailDivideProduction * createTermTailDivideProduction (void);

    FactorParenthesisProduction * createFactorParenthesisProduction (void);

    FactorNumberProduction * createFactorNumberProduction (void);
    
  protected:

    StartProduction * startProduction_;

    ExpressionProduction * expressionProduction_;

    ExpressionTailAddProduction * expressionTailAddProduction_;

    ExpressionTailSubtractProduction * expressionTailSubtractProduction_;

    EpsilonProduction * epsilonProduction_;

    TermProduction * termProduction_;

    TermTailMultiplyProduction * termTailMultiplyProduction_;

    TermTailDivideProduction * termTailDivideProduction_;

    FactorParenthesisProduction * factorParenthesisProduction_;

    FactorNumberProduction * factorNumberProduction_;
};

#endif //EXPRESSION_CALCULATOR_PRODUCTIONFLYWEIGHTFACTORY_H
