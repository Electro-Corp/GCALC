#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <regex>
#include <cmath>
#include "term.h"
#include <ctre.hpp>
#include <ctll.hpp>

#include "../java.h"
/*
  Class 
*/
class Term;
class Func {
  public:
    Func();
    Func(std::string funcStr, JavaHelper* jHelper);
    double solve(double x);
    void print();
    std::vector<Func>* getFuncs();
    ~Func();
  private:
    std::string funcStr;
    std::vector<Term> terms;
    std::vector<Func> funcs;
    void seperate();
    JavaHelper* jHelper;
}; 
#endif