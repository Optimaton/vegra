///@author
///@date
///@details
#ifndef __ATTRIB_HPP__
#define __ATTRIB_HPP__

namespace libsvg {

/// Enumeration of Web Safe Font Family
enum struct FontFamily {
	Arial,
	Helvetica,
	TimesNewRoman,
	Times,
	CourierNew,
	Courier,
	Verdana,
	Georgia,
	Palatino,
	Garamond,
	Bookman,
	ComicSansMS,
	TrebuchetMS,
	ArialBlack,
	Impact,
};

/// Function to convert given Font Family from enum type to string type
inline std::string to_string(const libsvg::FontFamily& fontFamily)
{
	switch (fontFamily) {
		case libsvg::FontFamily::Arial: return "Arial";
		case libsvg::FontFamily::Helvetica: return "Helvetica";
		case libsvg::FontFamily::TimesNewRoman: return "Times New Roman";
		case libsvg::FontFamily::Times: return "Times";
		case libsvg::FontFamily::CourierNew: return "Courier New";
		case libsvg::FontFamily::Courier: return "Courier";
		case libsvg::FontFamily::Verdana: return "Verdana";
		case libsvg::FontFamily::Georgia: return "Georgia";
		case libsvg::FontFamily::Palatino: return "Palatino";
		case libsvg::FontFamily::Garamond: return "Garamond";
		case libsvg::FontFamily::Bookman: return "Bookman";
		case libsvg::FontFamily::ComicSansMS: return "Comic Sans MS";
		case libsvg::FontFamily::TrebuchetMS: return "Trebuchet MS";
		case libsvg::FontFamily::ArialBlack: return "Arial Black";
		case libsvg::FontFamily::Impact: return "Impact";
	}
}

/*
 *enum struct Color {
 *  Black,
 *  Lime,
 *  Cyan,
 *  Aqua,
 *  Red,
 *  Fuschia,
 *  Magenta,
 *  Yellow,
 *  White,
 *};
 *
 *inline std::string to_string(const libsvg::Color& color)
 *{ 
 *  switch (color) {
 *    case libsvg::Color::Black: return "Black";
 *    case libsvg::Color::Lime: return "Lime";
 *    case libsvg::Color::Cyan: return "Cyan";
 *    case libsvg::Color::Aqua: return "Aqua";
 *    case libsvg::Color::Red: return "Red";
 *    case libsvg::Color::Fuschia: return "Fuschia";
 *    case libsvg::Color::Magenta: return "Magenta";
 *    case libsvg::Color::Yellow: return "Yellow";
 *    case libsvg::Color::White: return "White";
 *  }
 *}
 */

struct Position {
 public:
  Position() : x(0), y(0)
  {}
  Position(int x,int y) : x(x), y(y)
  {}
  inline void setPosition(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
  inline void setX(int x)
  {
    this->x = x;  
  }
  inline void setY(int y)
  {
    this->y = y;  
  }
  inline int getX()
  {
    return x;  
  }
  inline int getY()
  {
    return y;
  }

  inline Position getPosition()
  {
    return {x, y}; 
  }
  int x;
  int y;
};

struct Center {
 public:
  Center() : cx(0), cy(0)
  {}
  Center(int cx, int cy) : cx(cx), cy(cy)
  {}
  inline void setCenter(int cx, int cy)
  {
    this->cx = cx;
    this->cy = cy;
  }
  inline void setCX(int cx)
  {
    this->cx = cx;  
  }
  inline void setCY(int cy)
  {
    this->cy = cy;  
  }
  inline Center getCenter()
  {
    return {cx, cy};  
  }
  inline int getCX()
  {
    return cx;  
  }
  inline int getCY()
  {
    return cy;
  }
  int cx;
  int cy;
};

struct Radius {
 public: 
  Radius() : radius(0)
  {}
  Radius(size_t radius) : radius(radius)
  {}
  inline void setRadius(size_t radius)
  {
    this->radius = radius;  
  }
  inline Radius getRadius()
  {
    return radius;  
  }
  size_t radius;
};


struct Size {
 public:
  Size() : height(0), width(0)
  {}
  Size(int height, int width) : height(height), width(width)
  {}
  inline void setSize(int height, int width)
  {
    this->height = height;
    this->width = width;
  }
  inline void setHeight(int height)
  {
    this->height = height;  
  }
  inline void setWidth(int width)
  {
    this->width = width;  
  }
  inline Size getSize()
  {
    return {height, width};  
  }
  inline int  getHeight()
  {
    return height;  
  }
  inline int getWidth()
  {
    return width;  
  }

  int height;
  int width;
};

/// Attribute to outline the element
// TODO(raghu): bound checking
struct Stroke {
 public:
  using i_pair = std::pair<int, int>;
  Stroke() : color("black"),
             width(1),
             dasharray(std::make_pair(0,0)),
             dashoffset(0),
             linecap(""),
             opacity(1)
  {} 
  Stroke(std::string color, 
         size_t width,
         i_pair dasharray,
         size_t dashoffset,
         std::string linecap,
         double opacity
        ) : color(color),
            width(width),
            dasharray(dasharray),
            dashoffset(dashoffset),
            linecap(linecap),
            opacity(opacity)
  {}
  inline void setColor(std::string color)
  {
    this->color = color;
  }
  inline void setWidth(size_t width)
  {
    this->width = width;  
  }
  inline void setDashArray(i_pair dasharray)
  {
    this->dasharray = dasharray;  
  }
  inline void setDashOffset(size_t dashoffset)
  {
    this->dashoffset = dashoffset;  
  }
  inline void setLinecap(std::string linecap)
  {
    this->linecap = linecap;  
  }
  inline void setOpacity(double opacity)
  {
    this->opacity = opacity;  
  }
  inline std::string getColor()
  {
    return color;  
  }
  inline size_t getWidth()
  {
    return width;  
  }
  inline i_pair getDashAray()
  {
    return dasharray; 
  }
  inline size_t getDashOffset()
  {
    return dashoffset;
  }
  inline std::string getLinecap()
  {
    return linecap;  
  }
  inline double getOpacity()
  {
    return opacity;  
  }
  std::string color; /// stroke
  size_t width; /// stroke-width
  i_pair dasharray; /// stroke-dasharray
  size_t dashoffset; /// stroke-dashoffset
  std::string linecap; /// stroke-linecap
  // std::string linejoin
  // size_t miterlimit - not sure how to go ahead 
  double opacity; /// stroke-opacity
};

/// Attribute control fill inside the svg element
// TODO(raghu): check color for hex values and web safe strings
struct Fill {
 public:
  Fill() : color("black"), opacity(1)
  {} 
  Fill(std::string color, double opacity) : color(color), opacity(opacity)
  {}
  inline void setColor(std::string color)
  {
    this->color = color;
  }
  inline void setOpacity(double opacity)
  {
    this->opacity = opacity;
  }
  inline std::string getColor()
  {
    return color;  
  }
  inline double getOpacity()
  {
    return opacity;
  }
  std::string color; /// fill
  double opacity; /// fill-opacity
};

}

#endif // __ATTRIB_HPP__
