///@author
///@date
///@details
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

namespace vegra {

/// Base Exception
struct VegraException : public std::runtime_error {
 public:
 	explicit VegraException(const std::string& msg)
 	: std::runtime_error(msg)
 	{}
};

/// Invalid attrib exception - Throw when invalid attribute is passed to a function
struct InvalidAttribException : public vegra::VegraException {
 public:
 	explicit InvalidAttribException(const std::string& msg)
 	: vegra::VegraException("Invalid Attribute: " + msg)
 	{}
}; 

//// Invalid param exception - Throw when invalid paramter is passed to a function
struct InvalidParamException : public vegra::VegraException {
 public:
 	explicit InvalidParamException(const std::string& msg)
 	: vegra::VegraException("Invalid Param: " + msg)
 	{}
};  

/// Invalid Type Exception - Throw when a non svg type is passed
struct InvalidTypeException : public vegra::VegraException {
  public:
    explicit InvalidTypeException(const std::string& msg)
    : vegra::VegraException("Invalid Type: " + msg)
    {}
};

}

#endif // __EXCEPTION_H__
