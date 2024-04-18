#include "term.h"

double Term::solve(double x){
  return operatr * func->solve(x);
}

Term::~Term(){
  
}