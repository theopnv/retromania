#ifndef			GHOST_H
# define		GHOST_H

# include		<iostream>
# include		"AStar.hpp"
# include		"ACharacter.hpp"
# include		"AStarTypes.hpp"
# include		"TileType.hpp"

namespace retromania
{

class			AGhost : public ACharacter
{
  protected:

    static int		_blinkyPos;
    int			_target;
    int			_idxPath;
    aMap_t		_aMap;
    path_t		_path;

    void 		randomTarget();
    bool		isAtCrossway();
    int			findValidNear(const int);
  public:
    			AGhost(const pos_t &,
			       const map_t *,
			       const int,
       			       const std::string &);
    virtual		~AGhost();
    void 		setAMap(map_t const *);
    int			getTarget() const;
    path_t const	&getPath() const;
    void 		setPacTarget(const int);
    void 		chasePac();
    void 		updatePos();
    virtual void 	setTarget(const int, const int) = 0;
};
}
#endif			/* !GHOST_H */
