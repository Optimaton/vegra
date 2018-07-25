#include "example_svg.h"

// TODO(raghu): Needs complete refactor
void drawCircle(std::string svgTitle)
{
  using namespace vegra;
  
  SVG svg(svgTitle);
  Size size = {500, 500};
  svg.setSize(size);

  Circle circle;
  Center center = {250, 250};

  circle.setCenter(center);
  circle.setRadius(200);
  Fill fill;
  fill.setColor("blue");
  circle.setFill(fill);

  svg.add(&circle);
  svg.close();
  
}
