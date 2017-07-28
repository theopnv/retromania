#ifndef			GHOST_H
# define		GHOST_H

# include		<iostream>
# include		"AStar.hpp"
# include		"ACharacter.hpp"
# include		"AStarTypes.hpp"
# include		"TileType.hpp"
# include		"typedef.hpp"

namespace retromania
{

class			AGhost : public ACharacter
{
  protected:

    static int		_blinkyPos;
    int			_target;
    int			_idxPath;
    astar::Map		_aMap;
    astar::path_t	_path;

    void 		randomTarget();
    bool		isAtCrossway();
    int			findValidNear(const int);
  public:
    			AGhost(const Pos & pos,
			       const Sptr_t<Map> map,
			       const int id,
       			       const std::string &);
    virtual		~AGhost();

    void 		setAMap(const Sptr_t<Map> map);
    int			getTarget() const;
    astar::path_t const	&getPath() const;
    void 		setPacTarget(const int);
    void 		chasePac();
    void 		updatePos();
    virtual void 	setTarget(const int, const int) = 0;
};

}

#endif			/* !GHOST_H */
