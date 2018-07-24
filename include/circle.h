///@author
///@date
///@details
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

namespace vegra {

using SVGElementList = std::vector<vegra::SVGElement *>;
 
struct Circle : SVGElement {
 public:
  Circle() : _tagname("circle")
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
  {
     using namespace vegra;
     return _tagname +
            ASSIGN(attr::cx, STR(_center.cx)) +
            ASSIGN(attr::cy, STR(_center.cy)) +
            ASSIGN(attr::radius, STR(_radius.radius)) +
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

  inline void setCenter(vegra::Center center)
  {
    _center = center;
  }

  inline void setRadius(Radius radius)
  {
    _radius = radius;  
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
  
  inline vegra::Center getCenter()
  {
    return _center;  
  }

  inline vegra::Radius getRadius()
  {
    return _radius;  
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
  vegra::Center _center;
  vegra::Radius _radius;
  vegra::Stroke _stroke;
  vegra::Fill _fill;
  SVGElementList _elements;
  std::string _element;
  std::string _tagname;
};
 
  
}

#endif // __CIRCLE_H__
