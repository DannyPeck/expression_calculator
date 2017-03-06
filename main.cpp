#include <iostream>
#include "ExpressionParser.h"

int main (void)
{
  std::string expr_string;

  std::getline (std::cin, expr_string);

  ExpressionParser parser;
  std::cout << "Enter an expression (enter QUIT to exit):" << std::endl;
  while (expr_string != "QUIT")
  {
    int result = 0;
    try
    {
      result = parser.evaluate (expr_string);
    }
    catch (std::exception & e)
    {
      std::cout << e.what () << std::endl;
      std::getline (std::cin, expr_string);
      continue;
    }

    std::cout << result << std::endl;

    std::getline (std::cin, expr_string);
  }
}