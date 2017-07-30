#include <iostream>
#include "Nibbler.hpp"

namespace retromania
{

extern "C"
{
  std::shared_ptr<Nibbler> entryPoint()
  {
    return std::make_shared<Nibbler>();
  }
}

const std::string	Nibbler::_MAP_PATH = "games/nibbler/ressources/maps/basic.txt";
const std::string	Nibbler::_SPRITE_MAZE = "games/nibbler/ressources/sprites/maze30x30.png";
const std::string	Nibbler::_CONFIG_PATH = "games/nibbler/ressources/configs";
const std::string	Nibbler::_NAME = "Nibbler";


Nibbler::Nibbler(uint16_t const width, uint16_t const height)
	  : AGame(width, height)
{
  initTileIDTab();
  setConfig();
  _lastDirection = ACharacter::RIGHT;
}

Nibbler::~Nibbler()
{
}

void Nibbler::play()
{
  changeConfig();
  cleanSnake();
  goForward();
  setDirection();
  checkDeath();
  if (_state != OFF) {
    manageFruits();
    feedSnake();
    renderHero();
  }
}

void Nibbler::start()
{
  _state = ON;
  _lastDirection = ACharacter::RIGHT;
  try {
    loadMap(_MAP_PATH);
  } catch (std::exception& e) {
    throw;
  }
  initCharacter();
  initFruits();
}

void Nibbler::stop()
{
  _state = OFF;
  _fruits = 0;
}

void Nibbler::renderHero()
{
  ACharacter::Pos tmp = _hero->getPosition();

  for (auto& it : tmp) {
    _map->tiles.at(it) = SNAKE;
  }
}

void Nibbler::cleanSnake()
{
  ACharacter::Pos tmp = _hero->getPosition();

  for (auto& it : tmp)
    _map->tiles.at(it) = EMPTY;
}

void Nibbler::setDirection()
{
  switch (_command)
    {
      case UP:
	if (_lastDirection != ACharacter::DOWN) {
	  goUp();
	  _lastDirection = ACharacter::UP;
	}
	break;
      case DOWN:
	if (_lastDirection != ACharacter::UP) {
	  goDown();
	  _lastDirection = ACharacter::DOWN;
	}
	break;
      case LEFT:
	if (_lastDirection != ACharacter::RIGHT) {
	  goLeft();
	  _lastDirection = ACharacter::LEFT;
	}
	break;
      case RIGHT:
	if (_lastDirection != ACharacter::LEFT) {
	  goRight();
	  _lastDirection = ACharacter::RIGHT;
	}
	break;
      default:
	break;
      }
  }

void Nibbler::checkDeath()
{
  if (checkWall() || checkHit()) {
    _state = LOST;
    stop();
  }
}

bool Nibbler::checkWall()
{
  return _map->tiles.at(_hero->getPositionAt(0)) == WALL;
}

bool Nibbler::checkHit()
{
  ACharacter::Pos tmp;

  tmp = _hero->getPosition();
  for (auto it = tmp.begin() + 1; it != tmp.end(); ++it) {
    if (_hero->getPositionAt(0) == *it) {
      return true;
    }
  }
  return false;
}

}