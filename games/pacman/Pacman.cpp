#include <unistd.h>
#include <iostream>
#include "Pacman.hpp"

namespace retromania
{

extern "C"
{
  IGame		*entryPoint()
  {
    return new Pacman();
  }

}

const std::string	Pacman::_MAP_PATH	= "games/pacman/ressources/maps/basic.txt";
const std::string	Pacman::_NAME		= "Pacman";

Pacman::Pacman(uint16_t const width, uint16_t const height)
		: AGame(width, height)
{
  initTileIDTab();
  setConfig();
  loadMap(_MAP_PATH);	// Keep all these functions in construct for Protocol
  initCharacter();
  initDirsTab();
}

Pacman::~Pacman()
{
  delete _hero;
  delete _map;
  delete _config;
}

void	Pacman::play()
{
  if (_state == TRANSFORM) {
    _state = ON;
  }
  _map->tiles.at(_hero->getPositionAt(0)) = EMPTY;
  changeConfig();
  chooseNextDir();
  setDirection();
  goForward();
  eatGoms();
  renderHero();
  manageGhosts();
  usleep(50000);
}

void 	Pacman::start()
{
  _score->setValue(0);
  _state = ON;
  loadMap(_MAP_PATH);
  initCharacter();
  initGhost();
  initDirsTab();
  initGomsTab();
}

void 	Pacman::stop()
{
  _state = OFF;

  if (_hero)
    delete _hero;
  if (_ennemies.size())
    {
      for (auto it : _ennemies)
	delete it;
      _ennemies.clear();
    }
}

void 	Pacman::renderHero()
{
  _map->tiles.at(_hero->getPositionAt(0)) = PACMAN;
}

void 	Pacman::renderGom()
{
  for (int i = 0; i < _map->width * _map->height; i++) {
    if (_goms[i]) {
      _map->tiles.at(i) = GOM;
    }
  }
}

void 		Pacman::renderGhost(AGhost *ghost)
{
  if (ghost->getId() == BLINKY) {
    _map->tiles.at(ghost->getPositionAt(0)) = BLINKY;
  }
  if (ghost->getId() == INKY) {
    _map->tiles.at(ghost->getPositionAt(0)) = INKY;
  }
  if (ghost->getId() == PINKY) {
    _map->tiles.at(ghost->getPositionAt(0)) = PINKY;
  }
  if (ghost->getId() == CLYDE) {
    _map->tiles.at(ghost->getPositionAt(0)) = CLYDE;
  }
}
}
