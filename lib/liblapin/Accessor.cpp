#include "LibLapin.hpp"

namespace retromania
{


void 			LibLapin::setInput(InputType input)
{
  _input = input;
}

std::string const	&LibLapin::getName() const
{
  return _NAME;
}

InputType			LibLapin::getInput() const
{
  bunny_loop(_window, 25, (void*)this);
  return _input;
}

LibLapin::inputTab_t	&LibLapin::getInputTab()
{
  return _inputTab;
}

void 		LibLapin::setConfig(const Sptr_t<conf_t> config)
{
  _config = config;
  if (_configTab.size()) {
    for (auto &it : _configTab) {
      bunny_delete_clipable(it.second);
    }
    _configTab.clear();
  }
  initConfigTab();
}
}
