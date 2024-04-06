#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <regex>

#include <ctre.hpp>
#include <ctll.hpp>
/*
  Class 
*/
class Func {
  public:
    Func(std::string funcStr);
    double solve(double x);
    void print();
    std::vector<Func> getFuncs();

  private:
    std::string funcStr;
    std::vector<Func> funcs;
}; 
#endif