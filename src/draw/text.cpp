#include "text.h"

Text::Text(std::string text, int x, int y, int size, RGB rgb){
  this->x = x;
  this->y = y;
  this->size = size;
  this->rgb = rgb;
  this->text = text;
  TTF_Init();
  // Load fonts
  font = TTF_OpenFont("../assets/default.ttf", 28);
  if(!font){
    printf("Error loading default font! %s\n", TTF_GetError());
    exit(-1);
  }
}


void Text::Draw(SDL_Renderer* render){
  SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {rgb.r, rgb.g, rgb.b, 255});
  texture = SDL_CreateTextureFromSurface(render, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rect = {this->x, this->y, surface->w, surface->h};
  SDL_RenderCopy(render, texture, NULL, &rect);
}
