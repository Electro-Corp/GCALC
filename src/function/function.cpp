#include "function.h"

Func::Func(std::string _funcStr) {
    this->funcStr = _funcStr;

    std::vector<Func> sep;
    
    
    
    /*
    // ctre::match<"^\\(|\\)$| ">(funcStr);

    constexpr auto pattern = ctll::fixed_string("^\\(|\\)$| ");
    auto regex = ctre::regular_expression(pattern);

    constexpr auto match(std::string_view sv) noexcept {
        return ctre::match<patern>(sv);
    } 

    /*
    while (match) {
        funcStr[match.get_end()] = ""; // what the char is set to
        match = regex.match(funcStr, match.get_end());
    }
    */
    
    /*
    // Remove spaces, and open/closed parenthesis at the start/end
    // Ex.
    // ( 2 + 4 ) -> 2+4    
    funcStr = std::regex_replace(funcStr, std::regex("^\\(|\\)$| "), "");

    // Replaces all instances of - with +-1*
    // This might not be necaserry but ill do it anyway
    funcStr = std::regex_replace(funcStr, std::regex("-"), "+-1*");

    // Replace instances of x without a number before it with 1*x
    funcStr = std::regex_replace(funcStr, std::regex("^x|\\+x"), "+1*x");

    // Replace instances of x with a coefficient with *x
    funcStr = std::regex_replace(funcStr, std::regex("(?<=\\d)x"), "*x");
    */
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

double Func::solve(double x){
  return 0.1 * (x * x);
}