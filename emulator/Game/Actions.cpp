#include <unistd.h>
#include <algorithm>
#include <dirent.h>
#include "JsonParser.hpp"
#include <cstring>
#include "AGame.hpp"

namespace retromania
{

void 		AGame::goUp()
{
  _hero->setDirection(ACharacter::UP);
}

void 		AGame::goDown()
{
  _hero->setDirection(ACharacter::DOWN);
}

void 		AGame::goLeft()
{
  _hero->setDirection(ACharacter::LEFT);
}

void 		AGame::goRight()
{
  _hero->setDirection(ACharacter::RIGHT);
}

void 		AGame::goForward()
{
  switch (_hero->getDirection())
  {
    case ACharacter::UP:
      moveUp();
      break;
    case ACharacter::DOWN:
      moveDown();
      break;
    case ACharacter::LEFT:
      moveLeft();
      break;
    case ACharacter::RIGHT:
      moveRight();
      break;
  }
}

}
