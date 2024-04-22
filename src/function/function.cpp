#include "function.h"
#include "../ctreextra.hpp"
#include "../ctre-consts.hpp"

Func::Func(std::string _funcStr, JavaHelper* jHelper) {
  this->funcStr = _funcStr;
  this->jHelper = jHelper;
  std::cout << funcStr << "\n";
  funcStr = jHelper->regexReplace(funcStr, "^\\(|\\)$| ", "");
  std::cout << "funcstr after java: " << funcStr << "\n";
  seperate();
}

Func::Func() {
  this->funcStr = "";
}

void Func::print() {
  if (this->funcs.size() > 0) {
    for (auto& func : funcs) {  
      func.print();
    }
  } else {
    std::cout << this->funcStr << "\n";
  }
}


std::vector<Func>* Func::getFuncs() {
  return &(this->funcs);
}

double Func::solve(double x){
  //return 0.1 * (x * x);
  return (50 * sin(0.01 * x));
}

void Func::seperate() {
  // there is something wrong with i
  // it goes over the length even though it shouldnt
  // i kinda fixed it with the return statment but
  // it still dosent make sense that the for loop wouldnt stop
  for (int i = 0; i < funcStr.length(); i++) {
    if(i + 1 > funcStr.length()) return;
    if(funcStr[i] == '(') {
      getFuncs()->push_back(Func(funcStr.substr(i), jHelper));
    }
  }
}

Func::~Func(){
  
}