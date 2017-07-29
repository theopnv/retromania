#include <dirent.h>
#include <cstring>
#include <algorithm>
#include "Pacman.hpp"
#include "JsonParser.hpp"

namespace retromania
{

const std::string& Pacman::getName() const
{
  return _NAME;
}

const std::string& Pacman::getConfigPath() const
{
  return _CONFIG_PATH;
}

void Pacman::setInput(InputType command)
{
  _command = command;
}

}
