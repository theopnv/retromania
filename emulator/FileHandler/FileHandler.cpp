#include <iostream>
#include "FileHandler.hpp"

/*
** META
*/
namespace fileHandler
{

FileHandler::FileHandler(const std::string& path, const Type& type) :
	_path(path),
	_type(type),
	_directory(NULL)
{
}

FileHandler::~FileHandler()
{
  if (_file.is_open()) {
    _file.close();
  }

  if (_directory) {
    closedir(_directory);
  }
}

/*
** ACCESSORS
*/

const std::string& FileHandler::getPath() const
{
  return _path;
}

void FileHandler::setPath(const std::string& path)
{
  _path = path;
}

void FileHandler::setType(const Type& type)
{
  _type = type;
}

/*
** MEMBER FUNCTIONS
*/

void FileHandler::open()
{
  if (_type == FILE) {
    _file.open(_path.c_str(), std::ios::in|std::ios::out);
    if (!_file.good()) {
      throw exception::FileHandlerException("Can't open " + _path);
    }
  } else if (_type == DIR) {
    if (!(_directory = opendir(_path.c_str()))) {
      throw exception::FileHandlerException("Can't open " + _path);
    }
  }
}

std::string FileHandler::getLine(const char delim)
{
  std::string		line("");
  char			c;

  if (_file.is_open()) {
    while ((c = _file.get()) != EOF) {
      if (c != '\n') {
	line.push_back(c);
      }
      if (c == delim) {
	break;
      }
    }
  } else {
    throw exception::FileHandlerException("File wasn't open. Please Report this bug.");
  }
  return line;
}

std::string FileHandler::getCurrFileName()
{
  if (_directory) {
    if ((_currFileInDir = readdir(_directory))) {
      return (std::string)_currFileInDir->d_name;
    }
  } else {
    throw exception::FileHandlerException("Directory wasn't open. Please report this bug.");
  }

  return "";
}

}
