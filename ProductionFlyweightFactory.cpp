#include "ProductionFlyweightFactory.h"
#include "StartProduction.h"
#include "ExpressionProduction.h"
#include "ExpressionTailAddProduction.h"
#include "ExpressionTailSubtractProduction.h"
#include "EpsilonProduction.h"
#include "TermProduction.h"
#include "TermTailMultiplyProduction.h"
#include "TermTailDivideProduction.h"
#include "FactorParenthesisProduction.h"
#include "FactorNumberProduction.h"

ProductionFlyweightFactory::ProductionFlyweightFactory (void)
: startProduction_ (nullptr),
  expressionProduction_ (nullptr),
  expressionTailAddProduction_ (nullptr),
  expressionTailSubtractProduction_ (nullptr),
  epsilonProduction_ (nullptr),
  termProduction_ (nullptr),
  termTailMultiplyProduction_ (nullptr),
  termTailDivideProduction_ (nullptr),
  factorParenthesisProduction_ (nullptr),
  factorNumberProduction_ (nullptr)
{
}

ProductionFlyweightFactory::~ProductionFlyweightFactory (void)
{
  delete this->startProduction_;
  delete this->expressionProduction_;
  delete this->expressionTailAddProduction_;
  delete this->expressionTailSubtractProduction_;
  delete this->epsilonProduction_;
  delete this->termProduction_;
  delete this->termTailMultiplyProduction_;
  delete this->termTailDivideProduction_;
  delete this->factorParenthesisProduction_;
  delete this->factorNumberProduction_;
}

StartProduction * ProductionFlyweightFactory::createStartProduction (void)
{
  if (this->startProduction_ == nullptr)
  {
    this->startProduction_ = new StartProduction ();
  }

  return this->startProduction_;
}

ExpressionProduction * ProductionFlyweightFactory::createExpressionProduction (void)
{
  if (this->expressionProduction_ == nullptr)
  {
    this->expressionProduction_ = new ExpressionProduction ();
  }

  return this->expressionProduction_;
}

ExpressionTailAddProduction * ProductionFlyweightFactory::createExpressionTailAddProduction (void)
{
  if (this->expressionTailAddProduction_ == nullptr)
  {
    this->expressionTailAddProduction_ = new ExpressionTailAddProduction ();
  }

  return this->expressionTailAddProduction_;
}

ExpressionTailSubtractProduction * ProductionFlyweightFactory::createExpressionTailSubtractProduction (void)
{
  if (this->expressionTailSubtractProduction_ == nullptr)
  {
    this->expressionTailSubtractProduction_ = new ExpressionTailSubtractProduction ();
  }

  return this->expressionTailSubtractProduction_;
}

EpsilonProduction * ProductionFlyweightFactory::createEpsilonProduction (void)
{
  if (this->epsilonProduction_ == nullptr)
  {
    this->epsilonProduction_ = new EpsilonProduction ();
  }

  return this->epsilonProduction_;
}

TermProduction * ProductionFlyweightFactory::createTermProduction (void)
{
  if (this->termProduction_ == nullptr)
  {
    this->termProduction_ = new TermProduction ();
  }

  return this->termProduction_;
}

TermTailMultiplyProduction * ProductionFlyweightFactory::createTermTailMultiplyProduction (void)
{
  if (this->termTailMultiplyProduction_ == nullptr)
  {
    this->termTailMultiplyProduction_ = new TermTailMultiplyProduction ();
  }

  return this->termTailMultiplyProduction_;
}

TermTailDivideProduction * ProductionFlyweightFactory::createTermTailDivideProduction (void)
{
  if (this->termTailDivideProduction_ == nullptr)
  {
    this->termTailDivideProduction_ = new TermTailDivideProduction ();
  }

  return this->termTailDivideProduction_;
}

FactorParenthesisProduction * ProductionFlyweightFactory::createFactorParenthesisProduction (void)
{
  if (this->factorParenthesisProduction_ == nullptr)
  {
    this->factorParenthesisProduction_ = new FactorParenthesisProduction ();
  }

  return this->factorParenthesisProduction_;
}

FactorNumberProduction * ProductionFlyweightFactory::createFactorNumberProduction (void)
{
  if (this->factorNumberProduction_ == nullptr)
  {
    this->factorNumberProduction_ = new FactorNumberProduction ();
  }

  return this->factorNumberProduction_;
}