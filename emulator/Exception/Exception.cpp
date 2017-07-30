#include "Exception.hpp"

namespace exception
{

ProgException::ProgException(const std::string& message) throw()
{
  _message = message;
}

ProgException::ProgException() throw()
{
  _message = "";
}

ProgException::~ProgException() throw()
{
}

const char *ProgException::what() const throw()
{
  return _message.data();
}

}
