#ifndef TERM_HPP
#define TERM_HPP
#include "function.h"
#include <string>
// you have an insane cyclical dependency with term and func
class Func;
class Term {
public:
    Term(std::string str, int opr);        
    ~Term();    
    int operatr; // -1 or 1
    std::string term;
    Func *func;
    double solve(double x);
private:

};
#endif // TERM_HPP