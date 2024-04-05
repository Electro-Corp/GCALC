/*
*/
#ifndef LINE_H
#define LINE_H
#include "../drawable.h"
#include "../rgb.h"
class Line : public Drawable{
public:
  float x1, y1, x2, y2;
  RGB rgb;
  Line(float x, float y, float x1, float y1, RGB rgb);

  void Draw(SDL_Renderer* draw) override;
};
#endif