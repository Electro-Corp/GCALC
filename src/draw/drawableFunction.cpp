#include "drawableFunction.h"

DrawFunc::DrawFunc(Func* function){
  this->function = function;
  this->config = {
    0, 0,
    -800/2, 800/2,
    800, 400
  };
  rgb = RGB(0);
}

FUNCTION_DRAW_CONFIG* DrawFunc::getConfig(){
  return &(this->config);
}

void DrawFunc::Draw(SDL_Renderer* render){
  SDL_SetRenderDrawColor(render, rgb.r, rgb.g, rgb.b, rgb.a);
  float lX, lY;
  for(float x = this->config.xMin; x < this->config.xMax; x+=delta){
    SDL_RenderDrawPoint(render, (this->config.width / 2) - x, this->config.height - function->solve(x));
    if(x != this->config.xMin){
      SDL_RenderDrawLine(render, (this->config.width / 2) - x, this->config.height - function->solve(x), (this->config.width / 2) - lX, this->config.height - lY);
    }
    lX = x;
    lY = function->solve(x);
  }
}