#include "graphics.h"

Graphics::Graphics(std::string title, int width, int height){
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL INIT FAILURE ( %s )\n", SDL_GetError());
    exit(-1);
  }
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, 0);
}

void Graphics::addObj(Drawable* obj){
  drawables.push_back(obj);
};

void Graphics::handleInput(){
  SDL_Event e;
  SDL_PollEvent(&e);
  switch(e.type){
    case SDL_WINDOWEVENT:
      switch (e.window.event) {
        case SDL_WINDOWEVENT_CLOSE:
            exit(0);
            break;

        default:
            break;
      }
    break;
  }
}

void Graphics::tick(){
  handleInput();
  // Renderer
  SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, 255);
  SDL_RenderClear(renderer);

  for(auto& obj : drawables){
    obj->Draw(renderer);
  };
  
  
  SDL_RenderPresent(renderer);
}
