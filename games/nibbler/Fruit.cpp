#include <algorithm>
#include <random>
#include "Nibbler.hpp"

namespace retromania
{

void Nibbler::manageFruits()
{
  eatFruit();
  checkFruits();
  if (_fruits == 0)
    spawnFruit();
  if ( _fruits < 3) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> randomizator(0, 100);
    if (randomizator(rng) == 50) {
      spawnFruit();
    }
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
  if (_map->tiles.at(_hero->getPositionAt(0)) == FRUIT) {
    _score.setValue(_score.getValue() + 10);
    _fruits--;
    _justEaten = true;
    _queue = _hero->getPositionAt(_hero->getPosition().size() - 1);
  }
}

void Nibbler::feedSnake()
{
  if (_justEaten) {
    ACharacter::Pos tmp = _hero->getPosition();
    tmp.push_back(_queue);
    _hero->setPosition(tmp);
  }
  _justEaten = false;
}

void Nibbler::checkFruits()
{
  _fruits = 0;
  for (auto& it : _map->tiles) {
    if (it == FRUIT) {
      _fruits++;
     }
  }
}

}