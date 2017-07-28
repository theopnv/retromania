#include <utility>
#include <caca.h>
#include "IGraphic.hpp"
#include "LibCaca.hpp"

namespace retromania
{

void LibCaca::initColorTab()
{
  _colorTab.insert(std::make_pair(_WHITE, CACA_WHITE));
  _colorTab.insert(std::make_pair(_RED, CACA_RED));
  _colorTab.insert(std::make_pair(_BLUE, CACA_BLUE));
  _colorTab.insert(std::make_pair(_BLACK, CACA_BLACK));
  _colorTab.insert(std::make_pair(_YELLOW, CACA_YELLOW));
  _colorTab.insert(std::make_pair(_ORANGE, CACA_LIGHTRED));
  _colorTab.insert(std::make_pair(_CYAN, CACA_LIGHTCYAN));
  _colorTab.insert(std::make_pair(_PINK, CACA_MAGENTA));
  _colorTab.insert(std::make_pair(_GREEN, CACA_GREEN));
  _colorTab.insert(std::make_pair(_GREY, CACA_LIGHTGRAY));
}

void LibCaca::initInputTab()
{
  _inputTab.insert(std::make_pair(0, NONE));
  _inputTab.insert(std::make_pair(CACA_KEY_UP, UP));
  _inputTab.insert(std::make_pair(CACA_KEY_DOWN, DOWN));
  _inputTab.insert(std::make_pair(CACA_KEY_LEFT, LEFT));
  _inputTab.insert(std::make_pair(CACA_KEY_RIGHT, RIGHT));
  _inputTab.insert(std::make_pair(13, ENTER));
  _inputTab.insert(std::make_pair(32, SPACE));
  _inputTab.insert(std::make_pair(CACA_KEY_ESCAPE, ESC));
  _inputTab.insert(std::make_pair(CACA_KEY_F2, TWO));
  _inputTab.insert(std::make_pair(CACA_KEY_F3, THREE));
  _inputTab.insert(std::make_pair(CACA_KEY_F4, FOUR));
  _inputTab.insert(std::make_pair(CACA_KEY_F5, FIVE));
  _inputTab.insert(std::make_pair(CACA_KEY_F8, EIGHT));
  _inputTab.insert(std::make_pair(CACA_KEY_F9, NINE));
}
}
