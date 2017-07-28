#include "Blinky.hpp"

namespace retromania
{

Blinky::Blinky(const Pos &pos,
	       const Sptr_t<Map> map,
	       const int id,
	       const std::string &name)
	: AGhost(pos, map, id, name)
{
}

Blinky::~Blinky()
{

}

void 		Blinky::setTarget(const int pacPos, const int)
{
  _blinkyPos = _pos.at(0);
  _target = pacPos;
}
}
