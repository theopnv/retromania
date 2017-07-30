#include <fstream>
#include <algorithm>
#include "AGame.hpp"
#include "JsonParser.hpp"
#include "FileHandler.hpp"

namespace retromania
{

AGame::AGame(uint16_t const width, uint16_t const height)
{
  _map = std::make_shared<Map>();
  _map->width = width;
  _map->height = height;

  _score.setValue(0);
}

AGame::~AGame()
{
}

uint16_t AGame::getI(uint16_t const y, uint16_t const x) const
{
  return (y * _map->width + x);
}

uint16_t AGame::getY(uint16_t const i) const
{
  return (i / _map->width);
}

uint16_t AGame::getX(uint16_t const i) const
{
  return (i % _map->width);
}

const Sptr_t<conf_t> AGame::getConfig() const
{
  return _config;
}

const Score& AGame::getScore() const
{
  return _score;
}

const Sptr_t<Map> AGame::getMap() const
{
  return _map;
}

StateType AGame::getState() const
{
  return _state;
}

void AGame::loadMap(std::string const &path)
{
  std::string			line;
  fileHandler::FileHandler	fH(path.c_str(), fileHandler::FileHandler::Type::FILE);

  try {
    fH.open();
  } catch (std::exception& e) {
    std::cerr << "Can't load map (" << path << "). Exiting game" << std::endl;
    throw;
  }

  _map->tiles.clear();
  do {
    try {
      line = fH.getLine();
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
    for (unsigned int i = 0; i < line.size(); i++) {
      _map->tiles.push_back(line[i] - '0');
    }
  } while (line.size());
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

void AGame::setConfig()
{
  Sptr_t<JsonParser>		JParser;
  fileHandler::FileHandler	fH;
  std::string			fileName;
  std::vector<std::string>	files;
  const std::string		path = getConfigPath();

  /* Open config dir */
  fH.setPath(path);
  fH.setType(fileHandler::FileHandler::Type::DIR);
  try {
    fH.open();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  /* List files in config dir */
  do {
    try {
      fileName = fH.getCurrFileName();
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
    if (!(fileName.find(".json") == std::string::npos
	|| fileName.find(".json") != fileName.size() - 5)) {
      files.push_back(fileName);
    }
  } while (fileName != "");

  std::sort(files.begin(), files.end(), [](std::string const &a, std::string const &b) -> bool
  {
    return a < b;
  });

  for (auto& it : files) {
    JParser = std::make_shared<JsonParser>(path + "/" + it);
    _vconfigs.push_back(JParser->getConfig(_tileIDs));
  }
  if (_vconfigs.size() == 0) {
    throw std::runtime_error("No configuration file available. Please put one in the ressources/config/ directory.");
  }
  _config = *_vconfigs.begin();
  _current_config = 0;
}

}
