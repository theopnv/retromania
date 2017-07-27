#include <algorithm>
#include "Pacman.hpp"

namespace retromania
{


void 		Pacman::eatGoms()
{
  int		pos = _hero->getPositionAt(0);

  if (_map.tiles[pos] == GOM) {
    _goms[pos] = false;
    _map.tiles[pos] = EMPTY;
    _score.setValue(_score.getValue() + 10);
    ++_eaten;
  }

  renderGom();
  if (_eaten == _totalGoms) {
    start();
  }
}

void 		Pacman::manageGhosts()
{
  for (auto it : _ennemies) {
    _map.tiles.at(it->getPositionAt(0)) = EMPTY;
    it->setTarget(_hero->getPositionAt(0), _hero->getDirection());
    it->chasePac();
    if (it->getPath().size() <= 1) {
      it->setPacTarget(_hero->getPositionAt(0));
      it->chasePac();
    }
    if (it->getPositionAt(0) == _hero->getPositionAt(0)) {
      stop();
      break;
    } else {
      it->updatePos();
      renderGhost(it);
    }
  }
}
}
