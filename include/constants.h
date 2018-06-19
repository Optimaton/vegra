///@author
///@date
///@details
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

namespace vegra {

const std::string SPACE = " ";
const std::string EQUALS = "=";
const std::string OTAG = "<"; // opening tag
const std::string CTAG = ">"; // closing tag
const std::string FSLASH = "/";
const std::string DQUOTE = "\""; // double quote
const std::string COMMA = ",";
const std::string EXTENSION = ".svg";
namespace attr {
/// list all attributes
/// POSN
const std::string x = "x";
const std::string y = "y";
/// POSN OF CENTER FOR CIRCULAR SHAPES
const std::string cx = "cx";
const std::string cy = "cy";
/// SIZE
const std::string height = "height";
const std::string width = "width";
/// RADIUS
const std::string radius = "r";
/// FILL
const std::string fill = "fill";
const std::string fill_opacity = "fill-opacity";
/// STROKE
const std::string stroke = "stroke";
const std::string stroke_width = "stroke-width";
const std::string stroke_opacity = "stroke-opacity";
const std::string stroke_dasharray = "stroke-dasharray";
const std::string stroke_dashoffset = "stroke-dashoffset";
const std::string stroke_linecap = "stroke-linecap";
}


}

#endif // __CONSTANTS_H__
