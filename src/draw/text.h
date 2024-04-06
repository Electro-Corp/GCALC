#ifndef TEXT_H
#define TEXT_H
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "../drawable.h"
#include "../rgb.h"
class Text : public Drawable{
private:
  TTF_Font* font = NULL;
  SDL_Texture* texture;
  
  // Chat what do I need in the funciton abstract 
  // you need to run the SDL function that draws to the SDL_Renderer
public:
  RGB rgb;
  int x, y, size;
  std::string text;
  Text(std::string text, int x, int y, int size, RGB rgb);

  void Draw(SDL_Renderer* draw) override;
};
#endif