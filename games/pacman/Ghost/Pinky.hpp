#ifndef			PINKY8
# define		PINKY8

# include		"AGhost.hpp"

namespace retromania
{

class			Pinky : public AGhost
{
  public:
			Pinky(const pos_t &pos,
			      const Sptr_t<map_t> map,
			      const int id = PINKY,
			      const std::string &name = "Pinky");
			~Pinky();
    virtual void 	setTarget(const int, const int);
};
}
#endif			/* !PINKY8 */
