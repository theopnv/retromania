#include <iostream>
#include <memory>
#include "LibCaca.hpp"

namespace retromania
{

extern "C"
{
  std::shared_ptr<LibCaca> entryPoint()
  {
    return std::make_shared<LibCaca>();
  }
}

const std::string LibCaca::_NAME = "Libcaca";

LibCaca::LibCaca()
{
  initColorTab();
  initInputTab();
}

LibCaca::~LibCaca()
{

}
}
