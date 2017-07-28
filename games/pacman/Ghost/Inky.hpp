#ifndef			INKY_H
# define		INKY_H

# include		"AGhost.hpp"

namespace retromania
{

class			Inky : public AGhost
{
  public:
			Inky(const Pos &pos,
			     const Sptr_t<Map> map,
			     const int id = INKY,
			     const std::string &name = "Inky");
			~Inky();
    virtual void 	setTarget(const int, const int);
};
}
#endif			/* !INKY_H */
