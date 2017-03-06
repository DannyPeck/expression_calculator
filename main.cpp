#include <iostream>
#include "ExpressionParser.h"

int main (void)
{
  std::string expr_string;

  std::cout << "Enter an expression (enter QUIT to exit):" << std::endl;
  std::getline (std::cin, expr_string);

  ExpressionParser * parser;
  while (expr_string != "QUIT")
  {
    parser = new ExpressionParser ();
    int result = 0;
    try
    {
      result = parser->evaluate (expr_string);
    }
    catch (std::exception & e)
    {
      std::cout << e.what () << std::endl;
      std::getline (std::cin, expr_string);
      delete parser;
      continue;
    }

    std::cout << result << std::endl;

    std::getline (std::cin, expr_string);

    delete parser;
  }
}