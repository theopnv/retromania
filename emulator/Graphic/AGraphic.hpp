#ifndef			AGRAPHIC_H
# define		AGRAPHIC_H

# include		<iostream>
# include		"IGraphic.hpp"

# define SCALE(x)	((x) * _UNIT)

namespace retromania
{

class			AGraphic : public IGraphic
{
  protected:
    static const int	_MAP_TOP;	// Top border of the map
    static const int	_MAP_LEFT;	// Left border of the map
    conf_t const	*_config;

  public:
			AGraphic();
	  		~AGraphic();
  protected:
    virtual void 	setConfig(conf_t const *);
    virtual void 	blitTile(int const, retromania::pos_t &) = 0;
    void 		blitMap(const Sptr_t<map_t> map);
    void		error(const char *,
			      const unsigned int,
			      const std::string &) const;
};
}

#endif			/* !AGRAPHIC_H */
