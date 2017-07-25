#include <iostream>
#include "SDL.hpp"

namespace retromania
{

extern "C"
{
  IGraphic	*entryPoint()
  {
    return new SDL();
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
