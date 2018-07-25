/*!
 * @author Raghu Veer S
 * @version v0.1
 * @date 2018-04-12
 * @warning It only has few svg elements and few attributes.
 * @copyright MIT License
 * @mainpage vegra -  A basic header only svg library in c++
 * @section Introduction
 *  A basic header only svg library in c++. This is just a fun project.
 *  The aim of this project is to create a full fledged header only svg
 *  library.
 * @section Usage
 * This section tells how to use the code:
 * @subsection Prerequisites
 * You will need cmake, g++ 4.5 or above to compile the project.
 * @subsection Compilation
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

/**
 * vegra
 * vegra is a wordplay with vector and graphics.
 * Yeah, I know right. It is bad but we'll have do with it as I couldn't comeup with any witty names
 */
namespace vegra {

using SVGElementList = std::vector<vegra::SVGElement *>;
 
/**
 * SVG
 * Main element of type SVG
 * This class must wrap all other elements as there can be only one svg root
 */
struct SVG : SVGElement {
 public:
  SVG() : _tagname("svg")
  {
    _title = _tagname; 
  }

  SVG(std::string svgTitle) : 
    _tagname("svg"), _title(svgTitle)
  { }
  /**
   * add
   * This function adds other elements to the wrapping svg tag and also at the 
   * same time ensures that we do not break one root rule
   */
  inline void add();
  /**
   * add(SVGElement*)
   * This function adds other elements to the wrapping svg tag and also at the 
   * same time ensures that we do not break one root rule
   * @param SVGElement* This function takes in argument of type SVGElement,
   * which also happens to be the parent class for all the element class including SVG, 
   * as intenally SVG is also an element and it can be cascaded inside another svg tag
   */
  inline void add(vegra::SVGElement * element) 
  { 
    element->wrapElement();
    _elements.push_back(element);  
  }
  /**
   * add(SVGElement*, Args...)
   * This function adds other elements to the wrapping svg tag and also at the 
   * same time ensures that we do not break one root rule
   * @param SVGElement* This function takes in argument of type SVGElement,which also happens to be the parent class
   * class for all the element class including SVG, as intenally SVG is also an
   * element and it can be cascaded inside another svg tag, 
   * @param Args... This function also takes in a variadic parameter Args 
   * that is expected to be resolved into SVGElement type when used
   */
  template <typename... Args>
  inline void add(vegra::SVGElement* element, Args... args)
  {
    element->wrapElement();
    _elements.push_back(element);
    add(args...);
  }

  /**
   * composeElement()
   * This function composes the element tag for the current element
   * meaning it assigns all the attributes with corresponding values
   */
  inline std::string composeElement()
  {
     using namespace vegra;
     return _tagname +
            ASSIGN(attr::height, STR(_size.height)) +
            ASSIGN(attr::width, STR(_size.width)) +
            ASSIGN(attr::x, STR(_pos.x)) +
            ASSIGN(attr::y, STR(_pos.y));
  }
  
  /**
   * wrapElement()
   * This function wraps the composed tag and sub element tag
   * into a one giant tag. Essentially, this function takes care of 
   * hierarchichal tagging
   */
  inline void wrapElement()
  {
   using namespace vegra;
   if (_elements.empty())
     _element = WRAP(composeElement());
   else 
     _element = MULTI_WRAP(_tagname, composeElement(), getElements());
  }

  /**
   * checkIfSVGExists()
   * This function checks if the svg filename already exists
   * @return true if svg exists, else false
   */
  inline bool checkIfSVGExists()
  {
    _fname = _title + EXTENSION;
    std::ifstream svgFile(_fname);
    return svgFile.good();
  }

  /**
   * saveSVG()
   * This function call the wrap method and saves the svg in the filename
   * provided by the user
   */ 
  inline void saveSVG()
  {
    std::ofstream svgFile(_fname);
    wrapElement();
    svgFile << _element;
    svgFile.close();
  }
  
  /**
   * createNewTitle()
   * TODO(raghu): This function must created new title if the
   * user specified title already exists. Now you may ask how ?
   * Nothing fancy just keep the title as is and concatenate num
   * bers as suffix to the title, if the title with suffix is also
   * found then increment the suffix int untill you get a bad 
   * file stream
   */
  inline void createNewTitle()
  {
    
  }
      
  /**
   * close()
   * This function takes care of saving of file and resolving of 
   * filenames. User must call this function to save the svg, or else
   * all the work will be lost
   */ 
  inline void close()
  {
    if (checkIfSVGExists())
      createNewTitle();
    saveSVG();
  }
  
  /**
   * getElements()
   * @return vector of SVGElements
   */ 
  inline SVGElementList getElements()
  {
    return _elements;  
  }
  
  /** 
   * getPosition()
   * Function to get Position of SVG in the DOM
   * @return position of svg
   */
  inline vegra::Position getPos()
  {
    return _pos;
  }

  /**
   * getSize()
   * Function to get Size of SVG in the DOM
   * @return size of svg
   */
  inline vegra::Size getSize()
  {
    return _size;  
  }
  
  /**
   * getElement()
   * Function to return composed element
   * @return _element 
   */
  inline std::string getElement() override
  {
    return _element; 
  }

  /**
   * setPos()
   * Function to set Position of SVG in the DOM
   */
  inline void setPos(vegra::Position pos)
  {
    _pos = pos;
  }

  /**
   * setSize()
   * Function to set size of SVG wrt DOM
   */
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
