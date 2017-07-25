#ifndef			PACMAN_H
# define		PACMAN_H

# include		<unordered_map>
# include		"TileType.hpp"
# include		"AGame.hpp"
# include		"Blinky.hpp"
# include		"Inky.hpp"
# include		"Pinky.hpp"
# include		"Clyde.hpp"

namespace retromania
{

class			Pacman : public AGame
{

  typedef std::unordered_map<InputType, ACharacter::dir_t>	dirTab_t;
  typedef std::vector<bool>					boolTab_t;
  typedef std::vector<AGhost *>					ennemiesTab_t;

  private:
    static const std::string	_MAP_PATH;
    static const std::string	_NAME;

    boolTab_t		_aMap;
    ACharacter::dir_t	_pacNextDirection;
    dirTab_t		_dirs;
    boolTab_t		_goms;
    int			_eaten;
    int			_totalGoms;
    ennemiesTab_t	_ennemies;

    void 		setConfig();
    void 		setDirection();
    void 		chooseNextDir();
    void 		renderHero();
    void 		renderGom();
    void 		initDirsTab();
    void 		initGomsTab();
    void 		initCharacter();
    void 		initGhost();
    void 		initAMap();
    bool		isNotGhostHouse(const int);
    void 		eatGoms();
    void 		manageGhosts();
    void 		renderGhost(AGhost *);
  public:
			Pacman(uint16_t const width = 29,
			       uint16_t const height = 31);
			~Pacman();
    /* Inherited from IGame */
    virtual std::string const	&getName() const;
    virtual void	setInput(InputType);
    virtual void	play();
    virtual void 	start();
    virtual void 	stop();

    /* Inherited from AGame */
    virtual void 	moveUp();
    virtual void 	moveDown();
    virtual void 	moveLeft();
    virtual void 	moveRight();
    virtual void	initTileIDTab();
};
}
#endif			/* !PACMAN_H */
