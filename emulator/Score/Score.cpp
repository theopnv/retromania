#include "Score.hpp"

namespace retromania
{

Score::Score()
{
  _value = 0;
}

Score::~Score()
{
}

void 	Score::setValue(const int score)
{
  _value = score;
}

int	Score::getValue() const
{
  return _value;
}

}
