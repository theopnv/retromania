#include <random>
#include <sys/types.h>
#include "Nibbler.hpp"

namespace retromania
{

const std::string& Nibbler::getName() const
{
  return _NAME;
}

const std::string& Nibbler::getConfigPath() const
{
  return _CONFIG_PATH;
}

void Nibbler::setInput(InputType command)
{
  _command = command;
}

}