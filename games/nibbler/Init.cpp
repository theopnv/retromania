#include <random>
#include <dirent.h>
#include <cstring>
#include <algorithm>
#include "Nibbler.hpp"
#include "JsonParser.hpp"

namespace retromania
{

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

void 		Nibbler::setConfig()
{
  JsonParser	*JParser = NULL;
  DIR		*dir;
  struct dirent	*curr;
  std::string tmp;
  std::vector<std::string> files;
  const std::string path = "games/nibbler/ressources/configs";

  if (!(dir = opendir(path.c_str()))) {
	 std::cout << strerror(errno) << std::endl;
    }
  while ((curr = readdir(dir)) != NULL)
    {
	 tmp = curr->d_name;
	 if (!(tmp.find(".json") == std::string::npos || tmp.find(".json") != tmp.size() - 5))
	   files.push_back((std::string) curr->d_name);
    }
  closedir(dir);
  std::sort(files.begin(), files.end(), [](std::string const &a, std::string const &b) -> bool
  {
    return a < b;
  });
  for (auto& it : files)
    {
      JParser = new JsonParser(path + "/" + it);
      _vconfigs.push_back(JParser->getConfig(_tileIDs));
    }
  if (_vconfigs.size() == 0)
    {
      std::cerr << "CRITICAL ERROR: No nibbler config available!" << std::endl;
      exit(FAILURE);
    }
  _config = *_vconfigs.begin();
  _current_config = 0;
  if (JParser) {
    delete JParser;
  }
}
}
