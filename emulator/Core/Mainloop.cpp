#include <sstream>
#include "Emulator.hpp"

namespace retromania
{

void Emulator::options()
{
  /*
  ** Keys :
  ** ESC. Leave Emulator
  ** 2. Previous graphic	3. Next graphic
  ** 4. Previous game		5. Next game
  ** 8. restart the game	9. back to menu
  */

  aFp	fp;

  if (IS_MENU_KEY(_input)) {
    fp = _menuTab[_input];
    (this->*fp)();
  }
}

void Emulator::whereIsCursor(int const nbElem)
{
  if (_input == UP) {
    --_cursor;
  } else if (_input == DOWN) {
    ++_cursor;
  }

  if (_cursor < 0) {
    _cursor = nbElem - 1;
  }
  if (_cursor > nbElem - 1) {
    _cursor = 0;
  }
}

void Emulator::chooseLib()
{
  if (_input == ENTER) {
    if ((size_t)_cursor < _games.size()) {
      switchLibrary<IGame>(_cursor);
    } else if ((size_t)_cursor >= _games.size()
	       && (size_t)_cursor != _games.size() + _idxGraphic){
      switchLibrary<IGraphic>(_cursor - _games.size());
    }
  }
}

void Emulator::mainloop()
{
  while (!_leaveEmulator) {
    _input = _currGraphic->getInput();
    if (_inMenu) {
      affMenu();
      try {
	chooseLib();
      } catch (std::exception& e) {
	continue;
      }
      _currGraphic->display();
    } else {
      _currGame->setInput(_input);
      _currGame->play();
      _currGameState = _currGame->getState();
      _currGraphic->display(_currGame->getMap());
      if (_currGameState == TRANSFORM) {
	try {
	  _currGraphic->setConfig(_currGame->getConfig());
	} catch (std::runtime_error& e) {
	  std::cerr << e.what() << std::endl;
	}
      }
      if (_currGameState == OFF) {
	saveScore();
	backToMenu();
      }
    }
    options();
  }
}

void Emulator::saveScore()
{
  int	val;

  for (auto it : _scoreTab) {
    if (it.first == _currGame->getName()
	&& it.second->getValue() < _currGame->getScore().getValue()) {
      val = _currGame->getScore().getValue();
      it.second->setValue(val);
    }
  }
}

}
