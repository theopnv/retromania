#ifndef				AGAME_H
# define			AGAME_H

# include			<unordered_map>
# include			"IGame.hpp"
# include			"Score.hpp"
# include			"typedef.hpp"
# include			"ACharacter.hpp"

namespace retromania
{

class				AGame : public IGame
{
  public:
    typedef std::unordered_map<std::string, TileID>	tileIDTab_t;

  protected:

    tileIDTab_t			_tileIDs;
    InputType			_command;
    conf_t			*_config;
    std::vector<conf_t*> _vconfigs;
    int				_current_config;
    Sptr_t<map_t>		_map;
    Score			_score;
    ACharacter			*_hero;
    StateType			_state;

    uint16_t			getI(uint16_t const, uint16_t) const;
    uint16_t			getX(uint16_t const) const;
    uint16_t			getY(uint16_t const) const;
    void			loadMap(std::string const &);
    void 			changeConfig();
    virtual void		moveUp() = 0;
    virtual void		moveDown() = 0;
    virtual void		moveLeft() = 0;
    virtual void		moveRight() = 0;
    virtual void 		initTileIDTab() = 0;
  public:
				AGame(uint16_t const, uint16_t const);
				~AGame();
    virtual conf_t const	*getConfig() const;
    virtual Score const		&getScore() const;
    virtual StateType		getState() const;
    virtual void		goUp();
    virtual void		goDown();
    virtual void		goLeft();
    virtual void		goRight();
    virtual void 		goForward();
    virtual Sptr_t<map_t> const		getMap() const;
};
}
#endif				/* !AGAME_H */
