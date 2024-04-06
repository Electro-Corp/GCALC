#include <iostream>

#include "graphics.h"
#include "rgb.h"
#include "draw/line.h"
#include "draw/text.h"

#include "equation/equation.h"

int height = 600;
int widthRender = 800;
int renderYOffset = height / 2;
int renderXOffset = widthRender / 2;

int widthInput = 200;

int scale = 1;
int yAxisScale = 10;
int xAxisScale = 10;

void drawAxis(Graphics rWindow);

int main(){
  
  Graphics rWindow("Desmos But Bad", widthRender, height);
  Graphics iWindow("DBB Input", widthInput, height);

  rWindow.bg = RGB(255);
  iWindow.bg = RGB(100);

  RGB tempRGB {0};
  RGB red(255, 0, 0, 0);

  Line axisLineX(renderXOffset, 0, renderXOffset, height, tempRGB);
  Line axisLineY(0, renderYOffset, widthRender, renderYOffset, tempRGB);

  Line moveWithMouse1(0, 0, widthRender, height, red);
  Line moveWithMouse2(0, 0, widthRender, height, red);

  Text testText("Test", 0, 0, 20, tempRGB);

  // Equation
  Equation testEquation("x^2 + 3x + 2");
  

  rWindow.addObj(&axisLineX);
  rWindow.addObj(&axisLineY);
  rWindow.addObj(&moveWithMouse1);
  rWindow.addObj(&moveWithMouse2);
  rWindow.addObj(&testText);
  
  
  while(1) {
    rWindow.tick();
    testText.text = std::string{std::to_string((rWindow.mouseX - renderXOffset) * scale) + ", " + std::to_string((height - rWindow.mouseY - renderYOffset) * scale)};
    
    moveWithMouse1.y1 = rWindow.mouseY;
    moveWithMouse1.y2 = rWindow.mouseY;
    moveWithMouse2.x1 = rWindow.mouseX;
    moveWithMouse2.x2 = rWindow.mouseX;
    
    iWindow.tick();
  }

  drawAxis(rWindow);
}

/*void drawAxis(Graphics rWindow) {
  RGB tempRGB { 255 };
  rWindow.drawLine(0 + renderXOffset, 0, renderXOffset, height, tempRGB);
  rWindow.drawLine(0, renderYOffset, width, renderYOffset, tempRGB);

}*/