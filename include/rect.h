///@author
///@date
///@details
#ifndef __RECT_H__
#define __RECT_H__

namespace vegra {

using SVGElementList = std::vector<vegra::SVGElement *>;

struct Rect : SVGElement {
 public:
  Rect() : _tagname("rect")
  {}
  inline void add();

  inline void add(vegra::SVGElement * element) 
  {  
    _elements.push_back(element);  
  }

  template <typename... Args>
  inline void add(vegra::SVGElement* element, Args... args)
  {
    _elements.push_back(element);
    add(args...);
  }

 inline std::string composeElement()
 { using namespace vegra;
   return _tagname + 
          ASSIGN(attr::height, STR(_size.height)) +
          ASSIGN(attr::width, STR(_size.width)) +
          ASSIGN(attr::x, STR(_pos.x)) +
          ASSIGN(attr::y, STR(_pos.y)) +
          ASSIGN(attr::stroke, _stroke.color) +
          ASSIGN(attr::stroke_width, STR(_stroke.width)) +
          ASSIGN(attr::stroke_dasharray, STR(_stroke.dasharray)) +
          ASSIGN(attr::stroke_dashoffset, STR(_stroke.dashoffset)) +
           ASSIGN(attr::stroke_opacity, STR(_stroke.opacity)) +
           ASSIGN(attr::fill, _fill.color) +
           ASSIGN(attr::fill_opacity, STR(_fill.opacity));
 }

  inline void wrapElement()
  {
   using namespace vegra;
   if (_elements.empty())
     _element = WRAP(composeElement());
   else 
     _element = MULTI_WRAP(_tagname, composeElement(), _elements);
  }

  inline void setPos(vegra::Position pos)
  {
    _pos = pos;
  }

  inline void setSize(vegra::Size size)
  {
    _size = size;
  }

  inline void setStroke(vegra::Stroke stroke)
  {
    _stroke = stroke;  
  }

  inline void setFill(vegra::Fill fill)
  {
    _fill = fill;  
  }
 /// Funtion to get svg element list
  inline SVGElementList getElements()
  {
    return _elements;  
  }
 
  inline vegra::Position getPos()
  {
    return _pos;  
  }

  inline vegra::Size getSize()
  {
    return _size;  
  }
  
  inline vegra::Stroke getStroke()
  {
    return _stroke;  
  }

  inline vegra::Fill getFill()
  {
    return _fill;  
  }

  inline std::string getElement() override
  {
    return _element; 
  }
 protected:
 private:
  vegra::Position _pos;
  vegra::Size _size;
  vegra::Stroke _stroke;
  vegra::Fill _fill;
  SVGElementList _elements;
  std::string _element;
  std::string _tagname;
};

}

#endif // __RECT_H__
