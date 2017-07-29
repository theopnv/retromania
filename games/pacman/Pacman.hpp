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

  using dirTab_t	= std::unordered_map<InputType, ACharacter::Dir>;
  using boolTab_t	= std::vector<bool>;
  using ennemiesTab_t	= std::vector<std::shared_ptr<AGhost>>;

  private:
    static const std::string	_MAP_PATH;
    static const std::string	_NAME;
    static const std::string	_CONFIG_PATH;

    boolTab_t		_aMap;
    ACharacter::Dir	_pacNextDirection;
    dirTab_t		_dirs;
    boolTab_t		_goms;
    int			_eaten;
    int			_totalGoms;
    ennemiesTab_t	_ennemies;

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
    void 		renderGhost(Sptr_t<AGhost>);
    virtual const std::string&	getConfigPath() const;
  public:
			Pacman(uint16_t const width = 29,
			       uint16_t const height = 31);
			~Pacman();
    /* Inherited from IGame */
    virtual const std::string&	getName() const;
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
