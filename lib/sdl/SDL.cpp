#include <iostream>
#include <memory>
#include "SDL.hpp"

namespace retromania
{

extern "C"
{
  std::shared_ptr<SDL> entryPoint()
  {
    return std::make_shared<SDL>();
  }
}

const std::string	SDL::_FONT_PATH = "lib/sdl/ressources/font.ttf";
const size_t		SDL::_UNIT = 30;
const std::string	SDL::_NAME = "SDL";

SDL::SDL()
{
  initSDL();
  initTTF();
  initInputTab();
  initColorTab();
}

SDL::~SDL()
{
  TTF_Quit();
  SDL_Quit();
}
}
