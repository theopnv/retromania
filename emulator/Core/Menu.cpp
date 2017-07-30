#include "Emulator.hpp"

namespace retromania
{

void Emulator::leaveEmulator()
{
  _leaveEmulator = true;
}

void Emulator::prevGraphic()
{
  --_idxGraphic;
  if (_idxGraphic < 0) {
    _idxGraphic = _graphics.size() - 1;
  }
  switchLibrary<IGraphic>(_idxGraphic);
}

void Emulator::nextGraphic()
{
  ++_idxGraphic;
  if ((size_t)_idxGraphic >= _graphics.size()) {
    _idxGraphic = 0;
  }
  switchLibrary<IGraphic>(_idxGraphic);
}

void Emulator::prevGame()
{
  int	saveIdx = _idxGame;
  --_idxGame;
  if (_idxGame < 0) {
    _idxGame = _games.size() - 1;
  }
  try {
    switchLibrary<IGame>(_idxGame);
  } catch (std::exception& e) {
    _idxGame = saveIdx;
  }
}

void Emulator::nextGame()
{
  int	saveIdx = _idxGame;

  ++_idxGame;
  if ((size_t)_idxGame >= _games.size()) {
    _idxGame = 0;
  }
  try {
    switchLibrary<IGame>(_idxGame);
  } catch (std::exception& e) {
    _idxGame = saveIdx;
  }
}

void Emulator::restartGame()
{
  if (!_inMenu) {
    _currGame->stop();
    _currGame->start();
  }
}

void Emulator::backToMenu()
{
  _inMenu = true;
  _currGame = nullptr;
  _currGameState = OFF;
}

void Emulator::affMenu()
{
  size_t	nbElem;
  Pos		pos;

  pos.x = 12;
  pos.y = 2;
  _currGraphic->blitText("ARCADE", pos, 50, _YELLOW);

  pos.x = 5;
  pos.y = 8;
  nbElem = _games.size() + _graphics.size();
  whereIsCursor(nbElem);

  for (int i = 0; i < (int)_games.size(); i++) {
    if (i == _cursor)
      _currGraphic->blitText(_games[i].lib->getName(), pos, 30, _RED);
	   else
	 _currGraphic->blitText(_games[i].lib->getName(), pos, 30, _WHITE);
    pos.y += 3;
  }

  pos.y = 20;
  for (int i = 0; i < (int)_graphics.size(); i++) {
    if (i + (int)_games.size() == _cursor || i == (int)_idxGraphic) {
      _currGraphic->blitText(_graphics[i].lib->getName(), pos, 30, _RED);
    }
	 else
	 _currGraphic->blitText(_graphics[i].lib->getName(), pos, 30, _WHITE);
	 pos.y += 3;
  }
  affScores();
}

void Emulator::affScores()
{
  std::string	name, score;
  Pos		pos;

  pos.x = 20;
  pos.y = 8;

  for (auto &it : _scoreTab) {
    name = it.first;
    score = std::to_string(it.second->getValue());
    _currGraphic->blitText(name, pos, 30, _BLUE);
    pos.y += 3;
    _currGraphic->blitText(score, pos, 30, _BLUE);
    pos.y += 3;
  }
}

}
