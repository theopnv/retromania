#include "Nibbler.hpp"

namespace retromania
{

void 		Nibbler::moveUp()
{
  ACharacter::pos_t	pos = _hero->getPosition();

  for (size_t i = pos.size() - 1; i > 0; --i) {
    pos[i] = pos[i - 1];
  }
  pos[0] -= _map.width;
  _hero->setPosition(pos);
}

void 		Nibbler::moveDown()
{
  ACharacter::pos_t	pos = _hero->getPosition();

  for (size_t i = pos.size() - 1; i > 0; --i) {
    pos[i] = pos[i - 1];
  }
  pos[0] += _map.width;
  _hero->setPosition(pos);
}

void 		Nibbler::moveLeft()
{
  ACharacter::pos_t	pos = _hero->getPosition();

  for (size_t i = pos.size() - 1; i > 0; --i) {
    pos[i] = pos[i - 1];
  }
  --pos[0];
  _hero->setPosition(pos);
}

void 		Nibbler::moveRight()
{
  ACharacter::pos_t	pos = _hero->getPosition();

  for (size_t i = pos.size() - 1; i > 0; --i) {
    pos[i] = pos[i - 1];
  }
  ++pos[0];
  _hero->setPosition(pos);
}
}
