#include "ParseTree.h"

ParseTree::ParseTree (Symbol * root)
: root_ (root)
{
}

ParseTree::~ParseTree (void)
{
  delete this->root_;
}

int ParseTree::evaluate (void)
{
  return this->root_->evaluate ();
}