#include <unistd.h>
#include <dirent.h>
#include <typeinfo>
#include <cstring>
#include "Emulator.hpp"

namespace retromania
{

Emulator::Emulator(std::string const &defaultLib)
{
  initLibrairies(defaultLib);
  initMenuTab();
  initScore();
}

void Emulator::initScore()
{
  /* Init score Tab */
  for (auto &it : _games) {
    IScore	*score = new Score();

    score->setValue(0);
    _scoreTab.insert(std::make_pair(it.lib->getName(), score));
  }
}

void Emulator::initMenuTab()
{
  _menuTab.insert(std::make_pair(ESC, &Emulator::leaveEmulator));
  _menuTab.insert(std::make_pair(TWO, &Emulator::prevGraphic));
  _menuTab.insert(std::make_pair(THREE, &Emulator::nextGraphic));
  _menuTab.insert(std::make_pair(FOUR, &Emulator::prevGame));
  _menuTab.insert(std::make_pair(FIVE, &Emulator::nextGame));
  _menuTab.insert(std::make_pair(EIGHT, &Emulator::restartGame));
  _menuTab.insert(std::make_pair(NINE, &Emulator::backToMenu));
}

void Emulator::initLibrairies(std::string const &defaultLib)
{
  /* Set default graphic lib */
  _defaultLib = defaultLib;
  _graphics.push_back(getLibInstance<IGraphic>(_defaultLib));
  _idxGraphic = 0;
  _currGraphic = _graphics[_idxGraphic].lib;
  _currGraphic->createWindow();
  setLibraries();
  _currGame = nullptr;
  _leaveEmulator = false;
  _inMenu = true;
  _cursor = 0;
  _currGameState = OFF;
}

Emulator::~Emulator()
{
  _currGraphic->quitWindow();
  for (auto &it : _games) {
    it.loader->closeInstance();
  }
  for (auto &it : _graphics) {
    it.loader->closeInstance();
  }
  for (auto &it : _scoreTab) {
    delete it.second;
  }
}

void Emulator::setLibraries()
{
  openLibDir<IGame>("games", _games);
  openLibDir<IGraphic>("lib", _graphics);
}

/*
** Open a directory
** Fill a vector of structures with libraries and DLLoaders
*/

template <typename T>
void Emulator::openLibDir(std::string const &path, libTab_t<T> &libTab)
{
  DIR		*dir;
  struct dirent	*curr;

  if (!(dir = opendir(path.c_str()))) {
    std::cerr << strerror(errno) << std::endl;
  }
  while ((curr = readdir(dir)) != NULL) {
    if (DLLoader<void>::isDSOFile(curr->d_name)
	&& _defaultLib.find(curr->d_name) == std::string::npos) {
      libTab.push_back(getLibInstance<T>(path + "/" + curr->d_name));
    }
  }
  closedir(dir);
}

/*
** Fill a lib_t structure with a library and its DLLoader
*/

template <typename T>
Emulator::lib_t<T> Emulator::getLibInstance(std::string const &path)
{
  Emulator::lib_t<T>	newLib;
  Sptr_t<DLLoader<T>>	loader;

  newLib.loader = loader = std::make_shared<DLLoader<T>>();
  newLib.lib = loader->getInstance(path);
  return newLib;
}

template<>
void Emulator::switchLibrary<IGraphic>(const int idx)
{
  _currGraphic->quitWindow();
  _idxGraphic = idx;
  _currGraphic = _graphics[_idxGraphic].lib;
  _currGraphic->createWindow();
  if (_currGame) {
    _currGraphic->setConfig(_currGame->getConfig());
  }
}

template<>
void Emulator::switchLibrary<IGame>(const int idx)
{
  _idxGame = idx;
  _currGame = _games[_idxGame].lib;
  _inMenu = false;
  _currGame->start();
  _currGraphic->setConfig(_currGame->getConfig());
  _currGameState = ON;
}

}
