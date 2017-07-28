#include "AGraphic.hpp"

namespace retromania
{

const int		AGraphic::_MapOP = 1;
const int		AGraphic::_MAP_LEFT = 1;

AGraphic::AGraphic()
{
}

AGraphic::~AGraphic()
{
}

void 		AGraphic::setConfig(const Sptr_t<conf_t> config)
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

void 		AGraphic::blitMap(const Sptr_t<Map> map)
{
  retromania::Pos	pos;

  pos.y = _MapOP;
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
