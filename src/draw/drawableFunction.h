#ifndef DRAWFUNC_H
#define DRAWFUNC_H
/*
  Can draw a function
*/
#include "../drawable.h"
#include "../rgb.h"
#include "../function/function.h"

typedef struct {
  float xOffset, yOffset;
  int xMin, xMax, width, height;
} FUNCTION_DRAW_CONFIG;

class DrawFunc : public Drawable{
private:
  Func* function;
  FUNCTION_DRAW_CONFIG config;
  float delta = 1.0f;
public:
  RGB rgb;

  DrawFunc(Func* function);

  FUNCTION_DRAW_CONFIG* getConfig();

  void Draw(SDL_Renderer* draw) override;
};
#endif 