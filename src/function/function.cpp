#include "function.h"

Func::Func(std::string funcStr) {
  this->funcStr = funcStr;
  
  size_t pos = 0;
  while ((pos = this->funcStr.find("-", pos)) != std::string::npos) {
      this->funcStr.replace(pos, 1, "+-");
      pos += 2;
  }

  pos = 0;
  std::istringstream iss(this->funcStr);
  std::string part;

std::cout << "funcStr: " << this->funcStr << std::endl;
    
  auto count = std::ranges::count(funcStr, '+');
  int c = 0;
  std::cout << "count" << count << std::endl;
    
  while (++c < count) {
    std::getline(iss, part, '+');

    Func tmp { part };
    funcs.push_back(tmp);
      std::cout << part << std::endl;
  }    
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


std::vector<Func> Func::getFuncs() {
    return this->funcs;
}