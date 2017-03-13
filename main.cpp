#include <iostream>
#include "ExpressionParser.h"
#include "ParseTree.h"
#include "DivideByZeroException.h"
#include "InvalidDerivationException.h"

int main (void)
{
  std::string expr_string;

  std::cout << "Enter an expression (enter QUIT to exit):" << std::endl;
  std::getline (std::cin, expr_string);

  ExpressionParser * parser = new ExpressionParser ();
  ParseTree * parseTree;
  while (expr_string != "QUIT")
  {
    int result = 0;
    try
    {
      parseTree = parser->parse (expr_string);
      result = parseTree->evaluate ();
    }
    catch (InvalidDerivationException & e)
    {
      std::cout << e.what () << std::endl;
      std::getline (std::cin, expr_string);
      continue;
    }
    catch (DivideByZeroException & e)
    {
      std::cout << e.what () << std::endl;
      std::getline (std::cin, expr_string);
      delete parseTree;
      continue;
    }

    std::cout << result << std::endl;

    std::getline (std::cin, expr_string);

    delete parseTree;
  }

  delete parser;
}