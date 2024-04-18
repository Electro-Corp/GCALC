#include "function.h"
#include "../ctreextra.hpp"
#include "../ctre-consts.hpp"

Func::Func(std::string _funcStr, JavaHelper* jHelper) {
    this->funcStr = _funcStr;
    this->jHelper = jHelper;
    std::cout << funcStr << "\n";
    funcStr = jHelper->regexReplace(funcStr, "^\\(|\\)$| ", "");
    
    Func::seperate(*this);
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

Func Func::seperate(Func func) {
    std::string str = func.funcStr;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            func.getFuncs()->push_back(Func(str.substr(i), func.jHelper));
        }
    }
}

Func::~Func(){
  
}