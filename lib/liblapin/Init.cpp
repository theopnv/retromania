#include "LibLapin.hpp"

namespace retromania
{

void 		LibLapin::initColoredFonts()
{
  if (!_fonts.size()) {
    _fonts.insert(std::make_pair(_WHITE, openPicture("lib/liblapin/ressources/font-white.png")));
    _fonts.insert(std::make_pair(_RED, openPicture("lib/liblapin/ressources/font-red.png")));
    _fonts.insert(std::make_pair(_YELLOW, openPicture("lib/liblapin/ressources/font-yellow.png")));
    _fonts.insert(std::make_pair(_BLUE, openPicture("lib/liblapin/ressources/font-blue.png")));
  }
}

void 		LibLapin::initConfigTab()
{
  t_bunny_picture	*pic;

  if (_config != nullptr) {
    _configTab.clear();
    for (size_t i = 1; i <= _config->size(); i++) {
      pic = openPicture(_config->at(i).sprite.c_str());
      _configTab.insert(std::make_pair(i, pic));
    }
  }
}

void 		LibLapin::initInputTab()
{
  _inputTab.insert(std::make_pair(BKS_ESCAPE, ESC));
  _inputTab.insert(std::make_pair(BKS_RETURN, ENTER));
  _inputTab.insert(std::make_pair(BKS_UP, UP));
  _inputTab.insert(std::make_pair(BKS_DOWN, DOWN));
  _inputTab.insert(std::make_pair(BKS_LEFT, LEFT));
  _inputTab.insert(std::make_pair(BKS_RIGHT, RIGHT));
  _inputTab.insert(std::make_pair(BKS_SPACE, SPACE));
  _inputTab.insert(std::make_pair(BKS_F2, TWO));
  _inputTab.insert(std::make_pair(BKS_F3, THREE));
  _inputTab.insert(std::make_pair(BKS_F4, FOUR));
  _inputTab.insert(std::make_pair(BKS_F5, FIVE));
  _inputTab.insert(std::make_pair(BKS_F8, EIGHT));
  _inputTab.insert(std::make_pair(BKS_F9, NINE));
}
}
