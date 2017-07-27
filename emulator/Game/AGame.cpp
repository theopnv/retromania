#include <fstream>
#include "AGame.hpp"

namespace retromania
{

AGame::AGame(uint16_t const width, uint16_t const height)
{
  _map = std::make_shared<map_t>();
  _map->width = width;
  _map->height = height;

  _score.setValue(0);
}

AGame::~AGame()
{
  delete _hero;
}

uint16_t		AGame::getI(uint16_t const y, uint16_t const x) const
{
  return (y * _map->width + x);
}

uint16_t		AGame::getY(uint16_t const i) const
{
  return (i / _map->width);
}

uint16_t		AGame::getX(uint16_t const i) const
{
  return (i % _map->width);
}

conf_t const		*AGame::getConfig() const
{
  return _config;
}

Score const		&AGame::getScore() const
{
  return _score;
}

Sptr_t<map_t> const	AGame::getMap() const
{
  return _map;
}

StateType		AGame::getState() const
{
  return _state;
}

void 			AGame::loadMap(std::string const &path)
{
  std::ifstream		f;
  std::string		line;

  f.open(path.c_str());
  if (!f.good()) {
    std::cerr << "Can't open map located at " << path << std::endl;
    return;
  }

  _map->tiles.clear();
  while (getline(f, line)) {
    for (unsigned int i = 0; i < line.size(); i++) {
      _map->tiles.push_back(line[i] - '0');
    }
  }
  f.close();
}

void AGame::changeConfig()
{
  if (_command == SPACE)
    {
      if (_current_config == (int) (_vconfigs.size() - 1))
	_current_config = 0;
      else
        _current_config++;
      _config = _vconfigs[_current_config];
      _state = TRANSFORM;
    }
}

}
