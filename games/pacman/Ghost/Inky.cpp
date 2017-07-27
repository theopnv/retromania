#include "Inky.hpp"

namespace retromania
{

Inky::Inky(const pos_t &pos,
	   const map_t &map,
	   const int id,
	   const std::string &name)
		: AGhost(pos, map, id, name)
{
}

Inky::~Inky()
{

}

void 		Inky::setTarget(const int pacPos, const int)
{
  _target = -1 * (_blinkyPos - pacPos);
  _target += pacPos;
  _target = findValidNear(_target);
}
}
