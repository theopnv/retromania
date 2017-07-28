#include "Pinky.hpp"

namespace retromania
{

Pinky::Pinky(const Pos &pos,
	     const Sptr_t<Map> map,
	     const int id,
	     const std::string &name)
		: AGhost(pos, map, id, name)
{

}

Pinky::~Pinky()
{

}

void 		Pinky::setTarget(const int pacPos, const int pacDir)
{
  switch (pacDir)
  {
    case UP:
      _target = pacPos - _aMap.width;
      break;
    case DOWN:
      _target = pacPos + _aMap.width;
      break;
    case LEFT:
      _target = pacPos - 5;
      break;
    case RIGHT:
      _target = pacPos + 5;
      break;
    default:
      _target = pacPos;
  }
  if (_aMap.map[_target] == true
      || _target <= 0
      || _target >= _aMap.width * _aMap.height) {
    _target = findValidNear(_target);
  }
}
}
