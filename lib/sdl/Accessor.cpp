#include "SDL.hpp"

namespace retromania
{

std::string const	&SDL::getName() const
{
  return _NAME;
}

InputType		SDL::getInput() const
{
  SDL_Event	event;

  blitBackground();
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return ESC;
    } else if (event.type == SDL_KEYDOWN) {
      auto it = _inputTab.find(event.key.keysym.sym);
      if (it != _inputTab.end()) {
	return it->second;
      }
    }
  }
  return NONE;
}
}
