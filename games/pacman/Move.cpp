#include "Pacman.hpp"

namespace retromania
{

void 		Pacman::moveUp()
{
  ACharacter::Pos	pos = _hero->getPosition();

  if (_map->tiles[pos[0] - _map->width] != WALL) {
    pos[0] -= _map->width;
    _hero->setPosition(pos);
  }
}

void 		Pacman::moveDown()
{
  ACharacter::Pos	pos = _hero->getPosition();

  if (_map->tiles[pos[0] + _map->width] != WALL) {
    pos[0] += _map->width;
    _hero->setPosition(pos);
  }
}

void 		Pacman::moveLeft()
{
  ACharacter::Pos	pos = _hero->getPosition();

  if (_map->tiles[pos[0] - 1] != WALL) {
    --pos[0];
    _hero->setPosition(pos);
  }
}

void 		Pacman::moveRight()
{
  ACharacter::Pos	pos = _hero->getPosition();

  if (_map->tiles[pos[0] + 1] != WALL) {
    ++pos[0];
    _hero->setPosition(pos);
  }
}


void 	Pacman::setDirection()
{
  ACharacter::Pos	pos = _hero->getPosition();

  switch (_pacNextDirection)
  {
    case ACharacter::UP:
      if (_map->tiles[pos[0] - _map->width] != WALL) {
	goUp();
      }
      break;
    case ACharacter::DOWN:
      if (_map->tiles[pos[0] + _map->width] != WALL) {
	goDown();
      }
      break;
    case ACharacter::LEFT:
      if (_map->tiles[pos[0] - 1] != WALL) {
	goLeft();
      }
      break;
    case ACharacter::RIGHT:
      if (_map->tiles[pos[0] + 1] != WALL) {
	goRight();
      }
      break;
    default:
      break;
  }
}

void 	Pacman::chooseNextDir()
{
  if (_dirs.find(_command) != _dirs.end()) {
    _pacNextDirection = _dirs.at(_command);
  }
}
}
