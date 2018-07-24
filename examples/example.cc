#include <iostream>
#include "vegra.h"

// TODO(raghu): Needs complete refactor
int main()
{
  using namespace vegra;
  
  SVG svg;
  Position pos = {2, 3};
  Size size = {500, 500};
  svg.setPos(pos);
  svg.setSize(size);

  Rect rect;
  pos = {5, 3};
  size = {40, 70};
  rect.setPos(pos);
  rect.setSize(size);

  Rect rect2;
  pos = {4, 4};
  size = {30, 40};
  rect2.setPos(pos);
  rect2.setSize(size);
  Fill fill;
  fill.setColor("red");
  rect2.setFill(fill);

  svg.add(&rect, &rect2);

  Circle circle;
  circle.setRadius(20);
  Stroke stroke;
  stroke.setColor("blue");
  stroke.setWidth(10);
  circle.setStroke(stroke);
  
  
  svg.add(&circle);
  svg.close();
  
  return 0;
}
