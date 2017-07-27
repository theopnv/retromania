#include "Pacman.hpp"

namespace retromania
{

void 			Pacman::initTileIDTab()
{
  _tileIDs.insert(std::make_pair("WALL", WALL));
  _tileIDs.insert(std::make_pair("PACMAN", PACMAN));
  _tileIDs.insert(std::make_pair("BLINKY", BLINKY));
  _tileIDs.insert(std::make_pair("INKY", INKY));
  _tileIDs.insert(std::make_pair("PINKY", PINKY));
  _tileIDs.insert(std::make_pair("CLYDE", CLYDE));
  _tileIDs.insert(std::make_pair("GOM", GOM));
}

void 			Pacman::initDirsTab()
{
  _dirs.insert(std::make_pair(UP, ACharacter::UP));
  _dirs.insert(std::make_pair(DOWN, ACharacter::DOWN));
  _dirs.insert(std::make_pair(LEFT, ACharacter::LEFT));
  _dirs.insert(std::make_pair(RIGHT, ACharacter::RIGHT));
}

void 			Pacman::initCharacter()
{
  ACharacter::pos_t	pos;
  uint16_t		startPos;

  startPos = _map.width * ((_map.height / 2) + 2) + (_map.width / 2) - 2;
  pos.push_back(startPos);
  _hero = new ACharacter(pos, PACMAN, "Pacman");
  _hero->setDirection(ACharacter::RIGHT);
  _pacNextDirection = ACharacter::RIGHT;
}

bool 			Pacman::isNotGhostHouse(const int i)
{
  int			topLeftHouse = 331;
  int			topRightHouse = topLeftHouse + 5;

  for (int count = 0; count < 5; ++count) {
    if (i >= topLeftHouse && i <= topRightHouse) {
      return false;
    }
    topLeftHouse += _map.width;
    topRightHouse += _map.width;
  }
  return true;
}

void 			Pacman::initGomsTab()
{
  _eaten = 0;
  _totalGoms = 0;
  _goms.clear();
  _aMap.clear();	// Map for AStar
  for (size_t i = 0; i < _map.tiles.size(); i++) {
    if (_map.tiles[i] == EMPTY && isNotGhostHouse(i)) {
      _goms.push_back(true);
      _aMap.push_back(true);	// Map for AStar
      ++_totalGoms;
    } else {
      _goms.push_back(false);
      _aMap.push_back(false);	// Map for Astar
    }
  }
}

void 			Pacman::initGhost()
{
  ACharacter::pos_t	pos;
  int			gHouseLeft = 389;

  pos.push_back(gHouseLeft);
  Sptr_t<Blinky>	blinky = std::make_shared<Blinky>(pos, _map);
  _ennemies.push_back(blinky);

  pos.clear();
  pos.push_back(gHouseLeft + 1);
  Sptr_t<Inky>		inky = std::make_shared<Inky>(pos, _map);
  _ennemies.push_back(inky);

  pos.clear();
  pos.push_back(gHouseLeft + 2);
  Sptr_t<Pinky>		pinky = std::make_shared<Pinky>(pos, _map);
  _ennemies.push_back(pinky);

  pos.clear();
  pos.push_back(gHouseLeft + 3);
  Sptr_t<Clyde>		clyde = std::make_shared<Clyde>(pos, _map);
  _ennemies.push_back(clyde);
}
}
