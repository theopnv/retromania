#include "SDL.hpp"

namespace retromania
{

void		SDL::initSDL()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
    error(__FILE__, __LINE__, SDL_GetError());
  }
}

void 		SDL::initTTF()
{
  if (TTF_Init() == -1) {
    error(__FILE__, __LINE__, TTF_GetError());
  }
}
void 		SDL::initInputTab()
{
  _inputTab.insert(std::make_pair(SDLK_ESCAPE, ESC));
  _inputTab.insert(std::make_pair(SDLK_RETURN, ENTER));
  _inputTab.insert(std::make_pair(SDLK_UP, UP));
  _inputTab.insert(std::make_pair(SDLK_DOWN, DOWN));
  _inputTab.insert(std::make_pair(SDLK_LEFT, LEFT));
  _inputTab.insert(std::make_pair(SDLK_RIGHT, RIGHT));
  _inputTab.insert(std::make_pair(SDLK_SPACE, SPACE));
  _inputTab.insert(std::make_pair(SDLK_F2, TWO));
  _inputTab.insert(std::make_pair(SDLK_F3, THREE));
  _inputTab.insert(std::make_pair(SDLK_F4, FOUR));
  _inputTab.insert(std::make_pair(SDLK_F5, FIVE));
  _inputTab.insert(std::make_pair(SDLK_F8, EIGHT));
  _inputTab.insert(std::make_pair(SDLK_F9, NINE));
}

void		SDL::initColorTab()
{
  SDL_Color	white = {255, 255, 255, 0};
  SDL_Color	red = {255, 0, 0, 0};
  SDL_Color	blue = {0, 0, 255, 0};
  SDL_Color	yellow = {255, 255, 0, 0};
  SDL_Color	orange = {255, 135, 0, 0};
  SDL_Color	cyan = {0, 255, 255, 0};
  SDL_Color	pink = {255, 0, 255, 0};
  SDL_Color	green = {0, 255, 0, 0};
  SDL_Color	grey = {130, 130, 130, 0};

  _colorTab.insert(std::make_pair(_WHITE, white));
  _colorTab.insert(std::make_pair(_RED, red));
  _colorTab.insert(std::make_pair(_BLUE, blue));
  _colorTab.insert(std::make_pair(_YELLOW, yellow));
  _colorTab.insert(std::make_pair(_ORANGE, orange));
  _colorTab.insert(std::make_pair(_CYAN, cyan));
  _colorTab.insert(std::make_pair(_PINK, pink));
  _colorTab.insert(std::make_pair(_GREEN, green));
  _colorTab.insert(std::make_pair(_GREY, grey));
}
}
