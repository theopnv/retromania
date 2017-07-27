#include <iostream>
#include <zconf.h>
#include <thread>
#include <random>
#include <cstring>
#include <memory>
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
  const std::string	Nibbler::_NAME = "Nibbler";

  void 		Nibbler::initCharacter()
  {
    ACharacter::pos_t	pos;
    uint16_t		center;

    center = (_map->width * (_map->height / 2)) + _map->width / 2;
    pos.push_back(center);
    pos.push_back(center - 1);
    pos.push_back(center - 2);
    pos.push_back(center - 3);
    _hero = new ACharacter(pos, SNAKE, "Snake");
    _hero->setDirection(ACharacter::RIGHT);
  }

  Nibbler::Nibbler(uint16_t const width, uint16_t const height)
	  : AGame(width, height)
  {
    initTileIDTab();
    setConfig();
    loadMap(_MAP_PATH);
    initCharacter();	// Keep these functions in construct for Protocol
    _lastDirection = ACharacter::RIGHT;
  }

  Nibbler::~Nibbler()
  {
    if (_config)
      delete _config;
  }

  void 			Nibbler::initTileIDTab()
  {
    _tileIDs.insert(std::make_pair("WALL", WALL));
    _tileIDs.insert(std::make_pair("SNAKE", SNAKE));
    _tileIDs.insert(std::make_pair("FRUIT", FRUIT));
  }

  std::string const	&Nibbler::getName() const
  {
    return _NAME;
  }

  void	Nibbler::setInput(InputType command)
  {
    _command = command;
  }

  void	Nibbler::play()
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

  void 	Nibbler::start()
  {
    _state = ON;
    _lastDirection = ACharacter::RIGHT;
    loadMap(_MAP_PATH);
    initCharacter();
    initFruits();
  }

  void 	Nibbler::stop()
  {
    _state = OFF;
    _fruits = 0;
    if (_hero)
      delete _hero;
  }

  void Nibbler::renderHero()
  {
    ACharacter::pos_t tmp = _hero->getPosition();

    for (auto& it : tmp)
      {
	_map->tiles.at(it) = SNAKE;
      }
  }

  void Nibbler::cleanSnake()
  {
    ACharacter::pos_t tmp = _hero->getPosition();

    for (auto& it : tmp)
      _map->tiles.at(it) = EMPTY;
  }

  void Nibbler::setDirection()
  {
    switch (_command)
      {
	case UP:
	  if (_lastDirection != ACharacter::DOWN)
	    {
	      goUp();
	      _lastDirection = ACharacter::UP;
	    }
	break;
	case DOWN:
	  if (_lastDirection != ACharacter::UP)
	    {
	      goDown();
	      _lastDirection = ACharacter::DOWN;
	    }
	break;
	case LEFT:
	  if (_lastDirection != ACharacter::RIGHT)
	    {
	      goLeft();
	      _lastDirection = ACharacter::LEFT;
	    }
	break;
	case RIGHT:
	  if (_lastDirection != ACharacter::LEFT)
	    {
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
    if (checkWall() || checkHit())
      {
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
    ACharacter::pos_t tmp;

    tmp = _hero->getPosition();
    for (auto it = tmp.begin() + 1; it != tmp.end(); ++it)
      {
	if (_hero->getPositionAt(0) == *it)
	  return true;
      }
    return false;
  }

  void Nibbler::manageFruits()
  {
    eatFruit();
    checkFruits();
    if (_fruits == 0)
      spawnFruit();
    if ( _fruits < 3)
      {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> randomizator(0, 100);
	if (randomizator(rng) == 50)
	  spawnFruit();
      }
  }

  void Nibbler::spawnFruit()
  {
    int fruitPos;
    int randMax = _map->height * _map->width;

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> randomizator(0, (unsigned long) randMax - 1);

    do {
	fruitPos = (int) randomizator(rng);
      } while (_map->tiles.at(fruitPos) != EMPTY);
    _map->tiles.at(fruitPos) = FRUIT;
    _fruits++;
  }

  void Nibbler::eatFruit()
  {
    if (_map->tiles.at(_hero->getPositionAt(0)) == FRUIT)
      {
	_score->setValue(_score->getValue() + 10);
	_fruits--;
	_justEaten = true;
	_queue = _hero->getPositionAt(_hero->getPosition().size() - 1);
      }
  }

  void Nibbler::feedSnake()
  {
    if (_justEaten)
      {
	ACharacter::pos_t tmp = _hero->getPosition();
	tmp.push_back(_queue);
	_hero->setPosition(tmp);
      }
    _justEaten = false;
  }

  void Nibbler::checkFruits()
  {
    _fruits = 0;
    for (auto& it : _map->tiles)
      {
	if (it == FRUIT)
	  _fruits++;
      }
  }
}
