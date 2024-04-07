/*
  Manages (graphics) (wow)
*/
#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <string>
#include <vector>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "rgb.h"
#include "drawable.h"
class Graphics{
private:
  SDL_Window* window;
  SDL_Renderer* renderer;

  std::vector<Drawable*> drawables;
public:

  RGB bg;
  int mouseX = 0, mouseY = 0;

  Graphics(std::string title, int width, int height);

  void addObj(Drawable* obj);

  float getTicks();

  void handleInput();

  void tick();


  /*
    Draw funcs
  */
  //void drawLine(float x, float y, float x2, float y2, RGB color);
};
#endif