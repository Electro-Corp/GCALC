#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <regex>
#include <cmath>

#include <ctre.hpp>
#include <ctll.hpp>

#include "../java.h"
/*
  Class 
*/
class Func {
  public:
    Func(std::string funcStr, JavaHelper jHelper);
    double solve(double x);
    void print();
    std::vector<Func> getFuncs();

  private:
    std::string funcStr;
    std::vector<Func> funcs;
}; 
#endif