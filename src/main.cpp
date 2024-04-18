#include <iostream>
#include <string>

#include "graphics.h"
#include "rgb.h"
#include "java.h"
#include "draw/line.h"
#include "draw/text.h"
#include "draw/drawableFunction.h"

#include "function/function.h"

int height = 600;
int width = 800;
int renderYOffset = height / 2;
int renderXOffset = width / 2;

int viewPortXMin = -400, viewPortXMax = 400;

int widthInput = 200;

int scale = 1;
int yAxisScale = 10;
int xAxisScale = 10;

void drawAxis(Graphics rWindow);

int main(){
  JavaHelper jHelper;
  
  Graphics rWindow("Desmos But Bad", width, height);
  Graphics iWindow("DBB Input", widthInput, height);

  rWindow.bg = RGB(255);
  iWindow.bg = RGB(100);

  RGB tempRGB {0};
  RGB red(255, 0, 0, 0);

  Line axisLineX(renderXOffset, 0, renderXOffset, height, tempRGB);
  Line axisLineY(0, renderYOffset, width, renderYOffset, tempRGB);

  Line moveWithMouse1(0, 0, width, height, red);
  Line moveWithMouse2(0, 0, width, height, red);

  Text testText("Test", 0, 0, 28, tempRGB);
  Text fps("FPS", 0, 30, 28, tempRGB);

  // Equation
  std::string tempequation = "x^2 - 3x + 2 - sin(PI()x + 12x + 4) - cos(4PI()x - 4x) + x";
  std::string simple = "x^2 + 2x + 2";
  Func testEquation(tempequation, &jHelper);
  testEquation.print();

  DrawFunc testDrawFunc(&testEquation);
  testDrawFunc.rgb = RGB(0, 0, 255, 255);
  
  // Drawing Axis
  rWindow.addObj(&axisLineX);
  rWindow.addObj(&axisLineY);
  // Cursor
  rWindow.addObj(&moveWithMouse1);
  rWindow.addObj(&moveWithMouse2);
  // Coords
  rWindow.addObj(&testText);
  // Framerate
  rWindow.addObj(&fps);
  // Test function rendering
  rWindow.addObj(&testDrawFunc);

  int countedFrames = 0;
  
  while(1) {
    rWindow.tick();
    testText.text = std::string{std::to_string((rWindow.mouseX - renderXOffset) * scale) + ", " + std::to_string((height - rWindow.mouseY - renderYOffset) * scale)};
    fps.text = std::string{"FPS: " + std::to_string(rWindow.getTicks() / countedFrames)};
    FUNCTION_DRAW_CONFIG* config = testDrawFunc.getConfig();
    config->xMin = viewPortXMin;
    config->xMax = viewPortXMax;
    
    moveWithMouse1.y1 = rWindow.mouseY;
    moveWithMouse1.y2 = rWindow.mouseY;
    moveWithMouse2.x1 = rWindow.mouseX;
    moveWithMouse2.x2 = rWindow.mouseX;
    
    iWindow.tick();

    //
    countedFrames++;

    // Reset if its large 
    if(countedFrames > 200000){
      countedFrames = 0;
    }
  }
}