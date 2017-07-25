#include <iostream>
#include "LibCaca.hpp"

namespace retromania
{

extern "C"
{
  IGraphic	*entryPoint()
  {
    return new LibCaca();
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
