/*!
 * \author Raghu Veer S
 * \version 1.0
 * \date 2018-04-12
 * \warning It is not complete, It is just initial code and needs a lot of work.
 * \copyright MIT License
 * \mainpage vegra -  A basic header only svg library in c++
 * \section intro_sec Introduction
 *  A basic header only svg library in c++
 * \section compile_sec Compilation
 * 1. Navigate to build directory
 * 2. run cmake .. && make
 */
#ifndef __VEGRA_H__
#define __VEGRA_H__

#include <type_traits>
#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include "constants.h"
#include "exception.h"
#include "attrib.h"
#include "elements.h"
#include "rect.h"
#include "circle.h"

/// namespace vegra 
namespace vegra {

using SVGElementList = std::vector<vegra::SVGElement *>;
 
/// SVG element
struct SVG : SVGElement {
 public:
  SVG() : _tagname("svg")
  {
    _title = _tagname; 
  }
  
  inline void add();
  inline void add(vegra::SVGElement * element) 
  { 
    element->wrapElement();
    _elements.push_back(element);  
  }

  template <typename... Args>
  inline void add(vegra::SVGElement* element, Args... args)
  {
    element->wrapElement();
    _elements.push_back(element);
    add(args...);
  }

  inline std::string composeElement()
  {
     using namespace vegra;
     return _tagname +
            ASSIGN(attr::height, STR(_size.height)) +
            ASSIGN(attr::width, STR(_size.width)) +
            ASSIGN(attr::x, STR(_pos.x)) +
            ASSIGN(attr::y, STR(_pos.y));
  }
  
  inline void wrapElement()
  {
   using namespace vegra;
   if (_elements.empty())
     _element = WRAP(composeElement());
   else 
     _element = MULTI_WRAP(_tagname, composeElement(), getElements());
  }


  inline bool checkIfSVGExists()
  {
    _fname = _title + EXTENSION;
    std::ifstream svgFile(_fname);
    return svgFile.good();
  }

  inline void saveSVG()
  {
    std::ofstream svgFile(_fname);
    wrapElement();
    svgFile << _element;
    svgFile.close();
  }
  
  inline void createNewTitle()
  {
    
  }
      
  /// save svg and close the svg
  inline void close()
  {
    if (checkIfSVGExists())
      createNewTitle();
    saveSVG();
  }
  /// Funtion to get svg element list
  inline SVGElementList getElements()
  {
    return _elements;  
  }

  /// Function to get Position of SVG in the DOM
  inline vegra::Position getPos()
  {
    return _pos;
  }

  /// Function to get Size of SVG in the DOM
  inline vegra::Size getSize()
  {
    return _size;  
  }
  
  inline std::string getElement() override
  {
    return _element; 
  }

  /// Function to set Position of SVG in the DOM
  inline void setPos(vegra::Position pos)
  {
    _pos = pos;
  }

  /// Function to set Size of SVG wrt DOM
  inline void setSize(vegra::Size size)
  {
    _size = size;
  }

 protected:
 private:
  std::string _title;
  std::string _fname;
  vegra::Position _pos;
  vegra::Size _size;
  std::string _tagname;
  std::string _element;
  SVGElementList _elements;
};
 
}

#endif // __VEGRA_H__
