#include <caca.h>
#include "LibCaca.hpp"

namespace retromania
{

void 	LibCaca::createWindow()
{
  if (!(_dp = caca_create_display(NULL))) {
    std::cerr << "LibCaca can't open a new window" << std::endl;
  }
  _cv = caca_get_canvas(_dp);
  caca_set_display_title(_dp, "Retromania");
}

void	LibCaca::blitText(std::string const &text,
			  retromania::pos_t const &pos,
			  int const /*fontSize*/,
			  ColorType const color)
{
  caca_set_color_ansi(_cv, colorTab[color], CACA_BLACK);
  caca_put_str(_cv, pos.x, pos.y, text.c_str());
  usleep(500);
}

void 	LibCaca::quitWindow()
{
  caca_free_display(_dp);
}

void 	LibCaca::display(map_t const *map)
{
  if (map) {
    blitMap(map);
  }
  caca_refresh_display(_dp);
  if (map) {
    blitBackground(map);
    usleep(40000);
  }
  usleep(50000);
  caca_clear_canvas(_cv);
}

void 	LibCaca::blitBackground(map_t const *map)
{
  retromania::pos_t	pos;

  for (int i = 0; i < map->width * map->height; i++) {
    pos.x = i % map->width;
    pos.y = i / map->width;
    caca_set_color_ansi(_cv, CACA_BLACK, CACA_BLACK);
    caca_put_str(_cv, pos.x, pos.y, ".");
  }
}

void 	LibCaca::blitTile(const int tileID, retromania::pos_t &pos)
{
  caca_set_color_ansi(_cv, colorTab[_config->at(tileID).color],
		colorTab[_config->at(tileID).color]);
  caca_put_str(_cv, pos.x, pos.y, ".");
}
}
