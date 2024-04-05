#include "line.h"

Line::Line(float x1, float y1, float x2, float y2, RGB rgb){
  this->x1 = x1;
  this->x2 = x2;
  this->y1 = y1;
  this->y2 = y2;

  this->rgb = rgb;
}

void Line::Draw(SDL_Renderer* render){
  SDL_SetRenderDrawColor(render, rgb.r, rgb.g, rgb.b, 255);
  SDL_RenderDrawLine(render, x1, y1, x2, y2);
}