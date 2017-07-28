#include <iostream>
#include "LibCaca.hpp"

namespace retromania
{

const std::string & LibCaca::getName() const
{
  return _NAME;
}


InputType	LibCaca::getInput() const
{
  int key;

  if ((caca_get_event(_dp, CACA_EVENT_KEY_PRESS, (caca_event_t *) &_ev, 0)))
    key = caca_get_event_key_ch(&_ev);
  else
    key = 0;
  if (key == 0)
    return NONE;
  if (_inputTab.find(key) == _inputTab.end())
    {
	 return NONE;
    }
  return this->_inputTab.at(key);
}
}
