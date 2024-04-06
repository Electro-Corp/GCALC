#include "function.h"

Func::Func(std::string funcStr) {
  this->funcStr = funcStr;
  
  size_t pos = 0;
  while ((pos = funcStr.find("-", pos)) != std::string::npos) {
      funcStr.replace(pos, 1, "+-");
      pos += 2;
  }

  std::istringstream iss(funcStr);
  std::string part;

  while (std::getline(iss, part, '+')) {
      Func tmp { part };
      funcs.push_back(tmp);
  }
}