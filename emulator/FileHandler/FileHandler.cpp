#include <iostream>
#include "FileHandler.hpp"

/*
** META
*/
namespace retromania
{

FileHandler::FileHandler(const std::string & path, const std::string & strerr)
{
  _file.open(path.c_str(), std::ios::in|std::ios::out);
  if (!_file.good()) {
    std::cerr << strerr << std::endl;
  }
  _path = path;
}

FileHandler::~FileHandler()
{
  if (_file.is_open()) {
    _file.close();
  }
}

/*
** GETTERS
*/

std::string const &	FileHandler::getPath() const
{
  return _path;
}

/*
** MEMBER FUNCTIONS
*/

std::string		FileHandler::getLine(const char delim)
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
  }
  return line;
}
}
