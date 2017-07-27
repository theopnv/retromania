#ifndef			INKY_H
# define		INKY_H

# include		"AGhost.hpp"

namespace retromania
{

class			Inky : public AGhost
{
  public:
			Inky(const pos_t &pos,
			     const Sptr_t<map_t> map,
			     const int id = INKY,
			     const std::string &name = "Inky");
			~Inky();
    virtual void 	setTarget(const int, const int);
};
}
#endif			/* !INKY_H */
