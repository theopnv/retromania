#include "DLLoaderException.hpp"

namespace exception
{

DLLoaderException::DLLoaderException(const std::string& message) throw() :
	ProgException("DLLoaderException: " + message)
{
}

DLLoaderException::DLLoaderException() throw()
{
}

DLLoaderException::~DLLoaderException() throw()
{
}

}