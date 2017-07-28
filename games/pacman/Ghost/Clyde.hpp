#ifndef			CLYDE_H
# define		CLYDE_H

# include		"AGhost.hpp"

namespace retromania
{

class			Clyde : public AGhost
{
  public:
			Clyde(const Pos &pos,
			      const Sptr_t<Map> map,
			      const int id = CLYDE,
			      const std::string &name = "Clyde");
			~Clyde();
    virtual void 	setTarget(const int, const int);
};
}
#endif			/* !CLYDE_H */
