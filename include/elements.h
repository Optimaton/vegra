///@author
///@date
///@details
#ifndef __ELEMENTS_H__
#define __ELEMENTS_H__
#include "constants.h"

namespace libsvg {
/// SVGElement - Parent class for all svg elements
struct SVGElement {
 public:
  SVGElement() : _tagname("SVGElement")
  {}
  virtual void wrapElement() = 0;
  virtual std::string getElement() = 0;
 protected:
 private:
  std::string _tagname;
  std::string _element;
};

using SVGElementList = std::vector<libsvg::SVGElement *>;
 
/// utility wrapper functions
inline std::string QUOTE(std::string value) {return DQUOTE + value + DQUOTE;} /// TODO(raghu): Change to std::quoted if compiler is c++14 compliant
inline std::string WRAP(std::string value) {return OTAG + value + FSLASH + CTAG;} /// Wrap element with opening and closing tag, only with attributes
inline std::string MULTI_WRAP(std::string tagname, std::string self, SVGElementList elements) 
{
  std::string BEGIN = OTAG + self + CTAG;
  std::string stuffing;
  for (auto elem : elements)
    stuffing += elem->getElement() + "\n";
  std::string END = OTAG + FSLASH + tagname + CTAG;

  return BEGIN + stuffing + END;
}
inline std::string ASSIGN(std::string attr, std::string value) {return SPACE + attr + EQUALS + QUOTE(value) + SPACE;} /// Form assignment expr given attribute and value
/// convert all non string values to string type
inline std::string STR(int value) { return std::to_string(value); }
inline std::string STR(std::pair<int, int> value) { return std::to_string(value.first) + COMMA + std::to_string(value.second);}


}

#endif // __ELEMENTS_H_
