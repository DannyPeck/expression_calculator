#ifndef EXPRESSION_CALCULATOR_PRODUCTIONFACTORY_H
#define EXPRESSION_CALCULATOR_PRODUCTIONFACTORY_H

class StartProduction;
class ExpressionProduction;
class ExpressionTailAddProduction;
class ExpressionTailSubtractProduction;
class EpsilonProduction;
class TermProduction;
class TermTailMultiplyProduction;
class TermTailDivideProduction;
class FactorParenthesisProduction;
class FactorNumberProduction;

class ProductionFactory
{
  public:

    virtual StartProduction * createStartProduction (void) = 0;

    virtual ExpressionProduction * createExpressionProduction (void) = 0;

    virtual ExpressionTailAddProduction * createExpressionTailAddProduction (void) = 0;

    virtual ExpressionTailSubtractProduction * createExpressionTailSubtractProduction (void) = 0;

    virtual EpsilonProduction * createEpsilonProduction (void) = 0;

    virtual TermProduction * createTermProduction (void) = 0;

    virtual TermTailMultiplyProduction * createTermTailMultiplyProduction (void) = 0;

    virtual TermTailDivideProduction * createTermTailDivideProduction (void) = 0;

    virtual FactorParenthesisProduction * createFactorParenthesisProduction (void) = 0;

    virtual FactorNumberProduction * createFactorNumberProduction (void) = 0;
};

#endif //EXPRESSION_CALCULATOR_PRODUCTIONFACTORY_H
