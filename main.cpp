#include <iostream>
#include "ExpressionParser.h"
#include "ParseTree.h"

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
    catch (std::exception & e)
    {
      std::cout << e.what () << std::endl;
      std::getline (std::cin, expr_string);
      delete parseTree;
      continue;
    }

    std::cout << result << std::endl;

    std::getline (std::cin, expr_string);

    delete parser;
    delete parseTree;
  }
}