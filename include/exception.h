///@author
///@date
///@details
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

namespace libsvg {

/// Base Exception
struct libsvgException : public std::runtime_error {
 public:
 	explicit libsvgException(const std::string& msg)
 	: std::runtime_error(msg)
 	{}
};

/// Invalid attrib exception - Throw when invalid attribute is passed to a function
struct InvalidAttribException : public libsvg::libsvgException {
 public:
 	explicit InvalidAttribException(const std::string& msg)
 	: libsvg::libsvgException("Invalid Attribute: " + msg)
 	{}
}; 

//// Invalid param exception - Throw when invalid paramter is passed to a function
struct InvalidParamException : public libsvg::libsvgException {
 public:
 	explicit InvalidParamException(const std::string& msg)
 	: libsvg::libsvgException("Invalid Param: " + msg)
 	{}
};  

/// Invalid Type Exception - Throw when a non svg type is passed
struct InvalidTypeException : public libsvg::libsvgException {
  public:
    explicit InvalidTypeException(const std::string& msg)
    : libsvg::libsvgException("Invalid Type: " + msg)
    {}
};

}

#endif // __EXCEPTION_H__
