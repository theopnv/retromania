#ifndef			PINKY8
# define		PINKY8

# include		"AGhost.hpp"

namespace retromania
{

class			Pinky : public AGhost
{
  public:
			Pinky(const Pos &pos,
			      const Sptr_t<Map> map,
			      const int id = PINKY,
			      const std::string &name = "Pinky");
			~Pinky();
    virtual void 	setTarget(const int, const int);
};
}
#endif			/* !PINKY8 */
