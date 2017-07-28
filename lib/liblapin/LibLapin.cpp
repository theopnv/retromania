#include <iostream>
#include <memory>
#include "LibLapin.hpp"

namespace retromania
{

extern "C"
{
  std::shared_ptr<LibLapin> entryPoint()
  {
    return std::make_shared<LibLapin>();
  }
}

const int		LibLapin::_LETTER_WIDTH = 5;
const int		LibLapin::_LETTER_HEIGHT = 7;
const int		LibLapin::_FIRST_PRINTABLE = 33; /* 33 is the first printable ascii char */
const int		LibLapin::_UNIT = 30;
const std::string	LibLapin::_NAME	= "LibLapin";
const int		LibLapin::_WIN_WIDTH = 1000;
const int		LibLapin::_WIN_HEIGHT = 1000;

LibLapin::LibLapin()
{
  bunny_set_loop_main_function(&mainLoop);
  bunny_set_key_response(&keyResponse);
  initInputTab();
  _config = nullptr;
}

LibLapin::~LibLapin()
{
}


t_bunny_response	keyResponse(t_bunny_event_state state,
				    t_bunny_keysym sym,
				    void *data)
{
  LibLapin				*libLapin = (LibLapin *)data;
  std::map<t_bunny_keysym, InputType>	&inputTab = libLapin->getInputTab();

  if (state == GO_DOWN) {
    auto it = inputTab.find(sym);
    if (it != inputTab.end()) {
      libLapin->setInput(it->second);
      return EXIT_ON_SUCCESS;
    }
  }
  libLapin->setInput(NONE);
  return EXIT_ON_SUCCESS;
}

t_bunny_response	mainLoop(void *data)
{
  (void)data;
  return EXIT_ON_SUCCESS;
}
}
