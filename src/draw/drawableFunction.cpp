#include "drawableFunction.h"

DrawFunc::DrawFunc(Func* function){
  this->function = function;
  this->config = {
    0, 0,
    -800/2, 800/2,
    800, 600,
    1.0f
  };
  rgb = RGB(0);
}

FUNCTION_DRAW_CONFIG* DrawFunc::getConfig(){
  return &(this->config);
}

void DrawFunc::Draw(SDL_Renderer* render){
  // has the config changed?
  if(memcmp(&prevConfig, &config, sizeof(config)) != 0){
    // if so, we recalculate
    // clear buffer
    points.clear();
    // recalculate
    for(float x = this->config.xMin; x < this->config.xMax; x+=this->config.delta){
      points.push_back(
        {
          (this->config.width / 2) + x,
          (this->config.height / 2) - function->solve(x)
        }
      );
    }
  }

  SDL_SetRenderDrawColor(render, rgb.r, rgb.g, rgb.b, rgb.a);
  float lX, lY;

  for(int i = 0; i < points.size() - 1; i++){
    SDL_RenderDrawPoint(render, points[i].x, points[i].y);
    if(i != 0){
      SDL_RenderDrawLine(render, points[i].x, points[i].y, points[i - 1].x, points[i - 1].y);
    }
  }
  prevConfig = config;
}