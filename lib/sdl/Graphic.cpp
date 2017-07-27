#include "SDL.hpp"

namespace retromania
{

void 		SDL::createWindow()
{
  _window = SDL_CreateWindow("Retromania",
			     SDL_WINDOWPOS_CENTERED,
			     SDL_WINDOWPOS_CENTERED,
			     1000, 1000,
			     SDL_WINDOW_OPENGL);
  if (!_window) {
    error(__FILE__, __LINE__, SDL_GetError());
  }
  if (!(_renderer = SDL_CreateRenderer(_window, -1, 0))) {
    error(__FILE__, __LINE__, SDL_GetError());
  }
}

void 		SDL::quitWindow()
{
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
}

void		SDL::blitText(std::string const &text,
			      retromania::pos_t const &_pos,
			      int const fontSize,
			      ColorType const _color)
{
  SDL_Color	color;
  SDL_Rect	pos;
  SDL_Surface	*stext;
  SDL_Texture	*texture;
  TTF_Font	*font;

  pos.x = SCALE(_pos.x);
  pos.y = SCALE(_pos.y);
  color = _colorTab[_color];
  if (!(font = TTF_OpenFont(_FONT_PATH.c_str(), fontSize))
      || !(stext = TTF_RenderText_Solid(font, text.c_str(), color)))
    error(__FILE__, __LINE__, TTF_GetError());
  pos.h = fontSize;
  pos.w = stext->w;
  if (!(texture = SDL_CreateTextureFromSurface(_renderer, stext))
      || SDL_RenderCopy(_renderer, texture, NULL, &pos) < 0)
    error(__FILE__, __LINE__, SDL_GetError());

  TTF_CloseFont(font);
  SDL_FreeSurface(stext);
  SDL_DestroyTexture(texture);
}

void 		SDL::blitTile(const int tileID, retromania::pos_t &_pos)
{
  SDL_Surface	*surface;
  SDL_Texture	*texture;
  SDL_Rect	pos;

  pos.y = SCALE(_pos.y);
  pos.x = SCALE(_pos.x);
  pos.w = SCALE(1);
  pos.h = SCALE(1);
  if (!(surface = IMG_Load(_config->at(tileID).sprite.c_str())))
    error(__FILE__, __LINE__, IMG_GetError());
  if (!(texture = SDL_CreateTextureFromSurface(_renderer, surface))
      || SDL_RenderCopy(_renderer, texture, NULL, &pos) < 0)
    error(__FILE__, __LINE__, SDL_GetError());
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

void 		SDL::blitBackground() const
{
  SDL_Rect	bg;

  bg.x = bg.y = 0;
  bg.w = bg.h = 1000;
  if (SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255) < 0
      || SDL_RenderFillRect(_renderer, &bg) < 0)
    error(__FILE__, __LINE__, SDL_GetError());
}

void 		SDL::display(const Sptr_t<map_t> map)
{
  if (map) {
    blitMap(map);
  }
  SDL_RenderPresent(_renderer);
  SDL_Delay(70);
}
}
