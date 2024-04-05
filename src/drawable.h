/*
  Generic drawable object
*/
#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <SDL2/SDL.h>

class Drawable{
private:
public:
  virtual void Draw(SDL_Renderer* renderer) = 0;
};
#endif