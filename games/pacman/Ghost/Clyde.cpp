#include "Clyde.hpp"

namespace retromania
{

Clyde::Clyde(const pos_t &pos,
	     const Sptr_t<map_t> map,
	     const int id,
	     const std::string &name)
		: AGhost(pos, map, id, name)
{

}

Clyde::~Clyde()
{

}

void 		Clyde::setTarget(const int, const int)
{
  if (_path.size() < 2) {
    randomTarget();
  }
}
}
