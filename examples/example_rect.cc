#include "example_svg.h"

// TODO(raghu): Needs complete refactor
void drawRect(std::string svgTitle)
{
  using namespace vegra;
  
  SVG svg(svgTitle);
  Size size = {400, 110};
  svg.setSize(size);

  Rect rect;
  Position pos = {2, 3};
  pos = {5, 3};
  size = {300, 100};
  rect.setPos(pos);
  rect.setSize(size);
  Fill fill;
  fill.setColor("red");
  rect.setFill(fill);

  svg.add(&rect);
  svg.close();
  
}
