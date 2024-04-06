#include "function.h"

Func::Func(std::string funcStr) {
    this->funcStr = funcStr;
  
    // Replaces all instances of '-' with "+ -1*" 
    std::regex_replace(funcStr, std::regex("-"), "+ -1*");

    // Removes all spaces
    std::regex_replace(funcStr, std::regex(" "), "");
    
    // Mildly pointless 
    // Regex Statement that takes the first instance of an open parenthesis and takes all text inbetween it and the last closed parenthesis
    // std::regex parenthesis("\(.+\)");

    std::smatch match;
    std::regex_search(funcStr, match, std::regex("\\(([^)]+)\\)"));
    if (match.size() > 1) {
        std::string extracted = match.str(1);
        // Do something with extracted
    }
    
    // Removes first and last characters if the are opened and closed parenthesis respectively
    std::regex_replace(funcStr, std::regex("^\\(|\\)$"), "");
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