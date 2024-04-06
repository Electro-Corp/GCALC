#ifndef EQUATION_H
#define EQUATION_H

#include <vector>
#include <string>

class Equation : public Drawable {

  public:
    Equation(std::string equation);
  private:
    std::vector<Func> funcs;  
}
#endif // EQUATION_H