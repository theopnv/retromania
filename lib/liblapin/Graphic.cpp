#include "LibLapin.hpp"

namespace retromania
{

void 		LibLapin::createWindow()
{
  if (!(_window = bunny_start(_WIN_WIDTH, _WIN_HEIGHT, false, "Retromania"))) {
    bunny_printlerr("Cannot open the window");
  }
  _input = NONE;
  initColoredFonts(); // Do not put in constructor, because LibLapin is only initialized here.
}

void 		LibLapin::quitWindow()
{
  bunny_stop(_window);
}

t_bunny_picture		*LibLapin::openPicture(const char *path)
{
  t_bunny_picture	*tmp;

  if (!(tmp = bunny_load_picture(path))) {
    std::cerr << "Can't load " << path << std::endl;
  }
  return tmp;
}

void		LibLapin::blitText(std::string const &text,
				   retromania::pos_t const &tmpPos,
				   int const /*fontSize*/,
				   ColorType const color)
{
  t_bunny_picture	*font;
  t_bunny_position	pos;
  t_bunny_position	scaled;

  font = _fonts[color];
  font->scale.x = 4;
  font->scale.y = 4;
  font->clip_y_position = 0;
  font->clip_width = _LETTER_WIDTH;
  font->clip_height = _LETTER_HEIGHT;
  scaled.x = (font->clip_width + 1) * font->scale.x;
  scaled.y = font->clip_height * font->scale.y;

  pos.x = SCALE(tmpPos.x);
  pos.y = SCALE(tmpPos.y);
  for (int i = 0; text[i]; i++) {
    if (text[i] == ' ') {
      pos.x += scaled.x;
    } else {
      font->clip_x_position = (text[i] - _FIRST_PRINTABLE) * font->clip_width;
      bunny_blit(&_window->buffer, font, &pos);
      pos.x += scaled.x;
    }
  }
}

void 		LibLapin::blitBackground() const
{
  bunny_fill(&_window->buffer, ALPHA(255, BLACK));
}

void 		LibLapin::blitTile(int const tileID,
				   retromania::pos_t &_pos)
{
  t_bunny_position	pos;
  t_bunny_picture	*pic;

  pos.x = SCALE(_pos.x);
  pos.y = SCALE(_pos.y);
  pic = _configTab[tileID];
  pic->clip_x_position = pic->clip_y_position = 0;
  pic->clip_width = pic->clip_height = _UNIT;
  bunny_blit(&_window->buffer, pic, &pos);
}

void 		LibLapin::display(Sptr_t<map_t> const map)
{
  if (map) {
    blitMap(map);
  }
  bunny_display(_window);
  blitBackground();
  usleep(50000);
}
}
