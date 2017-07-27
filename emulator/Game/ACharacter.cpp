#include "ACharacter.hpp"
namespace retromania
{

ACharacter::ACharacter(const pos_t pos,
		       const int id,
		       const std::string &name)
{
  setPosition(pos);
  setId(id);
  setName(name);
}

ACharacter::~ACharacter()
{
}

void ACharacter::setId(const int id)
{
  _id = id;
}

void ACharacter::setName(const std::string &name)
{
  _name = name;
}

void ACharacter::setPosition(const pos_t pos)
{
  _pos = pos;
}

void ACharacter::setDirection(const dir_t &dir)
{
  _dir = dir;
}

int ACharacter::getId() const
{
  return _id;
}

std::string const & ACharacter::getName() const
{
  return _name;
}

ACharacter::pos_t ACharacter::getPosition() const
{
  return _pos;
}

int ACharacter::getPositionAt(const int i) const
{
  return _pos.at(i);
}

ACharacter::dir_t ACharacter::getDirection() const
{
  return _dir;
}
}
