#ifndef EQUATION_H
#define EQUATION_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "function/function.h"

class Equation {

  public:
    Equation(std::string equation);
  private:
    std::vector<Func> funcs;  
    std::string equation;
};
#endif // EQUATION_H