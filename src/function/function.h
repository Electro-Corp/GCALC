#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <vector>
#include <sstream>

/*
  Class 
*/
class Func {
  public:
    Func(std::string funcStr);
    double solve(double x);
  private:
    std::string funcStr;
    std::vector<Func> funcs;
}; 
#endif