#include "FileHandlerException.hpp"

namespace exception
{

FileHandlerException::FileHandlerException(const std::string& message) throw() :
	ProgException("FileHandlerException: " + message)
{
}

FileHandlerException::FileHandlerException() throw()
{
}

FileHandlerException::~FileHandlerException() throw()
{
}

}