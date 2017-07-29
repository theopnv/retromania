#include <random>
#include <dirent.h>
#include <cstring>
#include <algorithm>
#include "Nibbler.hpp"
#include "JsonParser.hpp"

namespace retromania
{

void Nibbler::initTileIDTab()
{
  _tileIDs.insert(std::make_pair("WALL", WALL));
  _tileIDs.insert(std::make_pair("SNAKE", SNAKE));
  _tileIDs.insert(std::make_pair("FRUIT", FRUIT));
}

void Nibbler::initFruits()
{
  int fruitPos;
  int randMax = _map->height * _map->width;
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> randomizator(0, (unsigned long) randMax - 1);
  _fruits = 0;
  do
    fruitPos = (int) randomizator(rng);
  while (_map->tiles.at(fruitPos) != EMPTY);
  _map->tiles.at(fruitPos) = FRUIT;
  _fruits++;
};

void Nibbler::initCharacter()
{
  ACharacter::Pos	pos;
  uint16_t		center;

  center = (_map->width * (_map->height / 2)) + _map->width / 2;
  pos.push_back(center);
  pos.push_back(center - 1);
  pos.push_back(center - 2);
  pos.push_back(center - 3);
  _hero = std::make_shared<ACharacter>(pos, SNAKE, "Snake");
  _hero->setDirection(ACharacter::RIGHT);
}

}
