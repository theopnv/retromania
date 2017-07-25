#ifndef			BLINKY_H
# define		BLINKY_H

# include		"AGhost.hpp"

namespace retromania
{

class			Blinky : public AGhost
{
  public:
			Blinky(const pos_t &pos,
			       const map_t *map,
			       const int id = BLINKY,
			       const std::string &name = "Blinky");
			~Blinky();
    virtual void 	setTarget(const int, const int);
};
}
#endif			/* !BLINKY_H */
