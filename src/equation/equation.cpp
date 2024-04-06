#include "equation.h"

Equation::Equation(std::string equation) {
  this->equation = equation;

  size_t pos = 0;
  while ((pos = equation.find("-", pos)) != std::string::npos) {
      equation.replace(pos, 1, "+-");
      pos += 2;
  }

  std::istringstream iss(equation);
  std::string part;
  
  while (std::getline(iss, part, '+')) {
      Func tmp { part };
      funcs.push_back(tmp);
  }
}