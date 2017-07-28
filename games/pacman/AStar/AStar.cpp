#include <algorithm>
#include "AStar.hpp"

namespace astar
{

AStar::AStar(const int pos, const int target, const Map &map)
{
  _map = map;
  _target.x = getX(target);
  _target.y = getY(target);

  for (size_t i = 0; i < map.map.size(); i++) {
    Cell	cell;

    cell.cell.y = cell.cell.x = -1;
    cell.G = cell.H = cell.F = 0;
    _close.array.push_back(cell);
    _open.array.push_back(cell);
  }

  _open.idx = _close.idx = 0;
  _open.array[0].cell.y = getY(pos);
  _open.array[0].cell.x = getX(pos);
  _open.array[0].parent = nullptr;
}

AStar::~AStar()
{

}

path_t const	&AStar::getPath()
{
  int		lower;
  bool		end = false;

  while (!end) {
    lower = calcLower();
    updateArrays(lower);
    addIn();
    end = endCondition();
  }
  flushPath();
  return _path;
}

int		AStar::getI(int const y, int const x) const
{
  return (y * _map.width + x);
}

int		AStar::getY(int const i) const
{
  return (i / _map.width);
}

int		AStar::getX(int const i) const
{
  return (i % _map.width);
}

bool		AStar::endCondition()
{
  if (_close.array[_lastOut].cell == _target)
    return true;
  return false;
}

int		AStar::calcLower() const
{
  size_t	i = -1;
  int		lower_i = 0;
  int		lower;

  lower = _map.map.size();
  while (_open.array[++i].cell.y != -1 && _open.array[i].F != 0) {
    if (_open.array[i].F < lower) {
      lower = _open.array[i].F;
      lower_i = i;
      if (_open.array[i + 1].F == 0) {
	return lower_i;
      }
    }
  }
  return lower_i;
}

void 		AStar::updateArrays(const int lower)
{
  _lastOut = _close.idx;
  if (_lastOut != (int)_map.map.size()
      && _close.array[_lastOut].cell.y
      && _open.array[lower].cell.y) {
    _close.array[_lastOut].cell = _open.array[lower].cell;
    _close.array[_lastOut].G = _open.array[lower].G;
    _close.array[_lastOut].H = _open.array[lower].H;
    _close.array[_lastOut].F = _open.array[lower].F;
    _close.array[_lastOut].parent = _open.array[lower].parent;
    ++_close.idx;
    _open.array[lower].F = _map.map.size();
  }
}

bool		AStar::inArray(Pos const &dir) const
{
  for (size_t i = 0; i < _map.map.size(); ++i) {
    if (dir == _close.array[i].cell) {
      return true;
    }
  }
  return false;
}

void 		AStar::addIn()
{
  int		i;
  Pos	dir[4] =
    {
      {_close.array[_lastOut].cell.y,
       _close.array[_lastOut].cell.x - 1},
      {_close.array[_lastOut].cell.y - 1,
       _close.array[_lastOut].cell.x},
      {_close.array[_lastOut].cell.y,
       _close.array[_lastOut].cell.x +1},
      {_close.array[_lastOut].cell.y + 1,
       _close.array[_lastOut].cell.x},
    };

  i = -1;
  while (++i < 4) {
    int idx2D = getI(dir[i].y, dir[i].x);
    if (idx2D >= 0 && idx2D < (int)_map.map.size()
	&& _map.map[idx2D] == false
	&& !inArray(dir[i])) {
      updateDistances(dir[i]);
    }
  }
}

void 		AStar::updateDistances(const Pos dir)
{
  Pos	H;

  ++_open.idx;
  _open.array[_open.idx].cell = dir;
  _open.array[_open.idx].parent = &_close.array[_lastOut];
  _open.array[_open.idx].G = _open.array[_open.idx].parent->G + 1;
  if ((H.x = _target.x - dir.x) < 0) {
    H.x *= -1;
  }
  if ((H.y = _target.y - dir.y) < 0) {
    H.y *= -1;
  }
  _open.array[_open.idx].H = H.y + H.x;
  _open.array[_open.idx].F = _open.array[_open.idx].G + _open.array[_open.idx].H;
}

AStar::Cell	*AStar::initParent()
{
  Cell	*parent = new Cell;

  parent->F = _close.array[_lastOut].F;
  parent->cell = _close.array[_lastOut].cell;
  parent->parent = _close.array[_lastOut].parent;
  return parent;
}

void 		AStar::flushPath()
{
  Cell	*parent;

  parent = initParent();
  while (parent != nullptr) {
    _path.push_back(getI(parent->cell.y, parent->cell.x));
    parent = parent->parent;
  }
}

bool		operator==(const AStar::Pos &a,
			   const AStar::Pos &b)
{
  return (a.y == b.y && a.x == b.x);
}
}
