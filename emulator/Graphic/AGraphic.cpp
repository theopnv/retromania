#include "AGraphic.hpp"

namespace retromania
{

const int		AGraphic::_MAP_TOP = 1;
const int		AGraphic::_MAP_LEFT = 1;

AGraphic::AGraphic()
{
}

AGraphic::~AGraphic()
{
}

void 		AGraphic::setConfig(conf_t const *config)
{
  _config = config;
}

void 		AGraphic::error(const char *file,
				const unsigned int line,
				const std::string &msg) const
{
  std::cout << "Error in " << file
	    << " at line " << line
	    << " : " << msg << std::endl;
}

void 		AGraphic::blitMap(const Sptr_t<map_t> map)
{
  retromania::pos_t	pos;

  pos.y = _MAP_TOP;
  pos.x = _MAP_LEFT;
  for (int i = 0; i < map->width * map->height; i++) {
    if (map->tiles[i] != 0) {	// 0 is already rendered by the black background
      blitTile(map->tiles[i], pos);
    }
    ++pos.x;
    if (!((i + 1) % map->width)) {
      ++pos.y;
      pos.x = _MAP_LEFT;
    }
  }
}
}
