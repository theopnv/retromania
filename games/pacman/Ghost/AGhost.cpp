#include <random>
#include "AGhost.hpp"

namespace retromania
{

int	AGhost::_blinkyPos = -1;

AGhost::AGhost(const Pos &pos,
	       const Sptr_t<Map> map,
	       const int id,
	       const std::string &name)
		: ACharacter(pos, id, name)
{
  setAMap(map);
}

AGhost::~AGhost()
{

}

void 		AGhost::randomTarget()
{

  unsigned long	randMax = _aMap.width * _aMap.height;

  std::mt19937	rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type>
	randomizator(_aMap.width, randMax);

  do {
    _target = (int)randomizator(rng);
  } while (_target > 0 && _target < (int)randMax && _aMap.map.at(_target) == true);
}

int		AGhost::getTarget() const
{
  return _target;
}

astar::path_t const	&AGhost::getPath() const
{
  return _path;
}

void 		AGhost::setPacTarget(const int pacPos)
{
  _target = pacPos;
}

void 		AGhost::setAMap(const Sptr_t<Map> map)
{
  for (auto &it : map->tiles) {
    _aMap.map.push_back(it > 0 ? true : false);
  }
  _aMap.width = map->width;
  _aMap.height = map->height;
}

bool		AGhost::isAtCrossway()
{
  int		i = 0;

  if (_aMap.map[_pos[0] - 1] == false)
    ++i;
  if (_aMap.map[_pos[0] + 1] == false)
    ++i;
  if (_aMap.map[_pos[0] - _aMap.width] == false)
    ++i;
  if (_aMap.map[_pos[0] + _aMap.width] == false)
    ++i;
  if (i > 2)
    return true;
  return false;
}

void 		AGhost::chasePac()
{
  astar::AStar	astar(_pos[0], _target, _aMap);

  try {
    _path = astar.getPath();
  } catch (std::exception &e) {}
}

void 		AGhost::updatePos()
{
  _pos.at(0) = _path[_path.size() - 2];
  _path.pop_back();
}

int		AGhost::findValidNear(const int pos)
{
  const int	size = _aMap.width * _aMap.height;

  for (int i = pos - 3; i < pos + 3; ++i) {
    if (i > 0 && i <= size - 1 && _aMap.map.at(i) == false) {
      return i;
    }
  }
  for (int i = pos - _aMap.width * 3; i < _aMap.width * 3; i++) {
    if (i >= 0 && i <= size && _aMap.map.at(i) == false) {
      return i;
    }
  }
  return _aMap.width + 1;
}
}
