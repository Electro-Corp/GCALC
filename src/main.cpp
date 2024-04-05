#include <iostream>

#include "graphics.h"
#include "rgb.h"
#include "draw/line.h"

int height = 600;
int widthRender = 800;
int renderYOffset = height / 2;
int renderXOffset = widthRender / 2;

int widthInput = 200;

void drawAxis(Graphics rWindow);

int main(){
  Graphics rWindow("Desmos But Bad", widthRender, height);
  Graphics iWindow("DBB Input", widthInput, height);

  rWindow.bg = RGB(255);
  iWindow.bg = RGB(100);

  RGB tempRGB {0};

  Line axisLineX(0 + renderXOffset, 0, renderXOffset, height, tempRGB);
  Line axisLineY(0, renderYOffset, widthRender, renderYOffset, tempRGB);

  rWindow.addObj(&axisLineX);
  rWindow.addObj(&axisLineY);
  
  
  while(1) {
    rWindow.tick();
    iWindow.tick();
  }

  drawAxis(rWindow);
}

/*void drawAxis(Graphics rWindow) {
  RGB tempRGB { 255 };
  rWindow.drawLine(0 + renderXOffset, 0, renderXOffset, height, tempRGB);
  rWindow.drawLine(0, renderYOffset, width, renderYOffset, tempRGB);

}*/