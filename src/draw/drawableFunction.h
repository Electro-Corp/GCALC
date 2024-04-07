#ifndef DRAWFUNC_H
#define DRAWFUNC_H
/*
  Can draw a function
*/
#include "../drawable.h"
#include "../rgb.h"
#include "../function/function.h"

#include <vector>

typedef struct {
  float xOffset, yOffset;
  int xMin, xMax, width, height;
  float delta;
} FUNCTION_DRAW_CONFIG;

typedef struct {
  float x, y;
} POINT;

class DrawFunc : public Drawable{
private:
  Func* function;
  FUNCTION_DRAW_CONFIG config , prevConfig;
  std::vector<POINT> points;
public:
  RGB rgb;

  DrawFunc(Func* function);

  FUNCTION_DRAW_CONFIG* getConfig();

  void Draw(SDL_Renderer* draw) override;
};
#endif 