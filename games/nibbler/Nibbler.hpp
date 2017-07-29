#ifndef			NIBBLER_H
# define		NIBBLER_H

# include		"AGame.hpp"

namespace retromania
{

class			Nibbler : public AGame
{
  enum 	TileType
  {
    EMPTY = 0,
    WALL,
    SNAKE,
    FRUIT
  };

  private:
    static const std::string	_MAP_PATH;
    static const std::string	_SPRITE_MAZE;
    static const std::string	_NAME;
    static const std::string	_CONFIG_PATH;

    unsigned int 		_fruits  = 0;
    bool 			_justEaten = false;
    int 			_queue;
    ACharacter::Dir 		_lastDirection;

    virtual void	initTileIDTab();
    void 		initCharacter();
    void		renderHero();
    void 		cleanSnake();
    void		setDirection();
    void 		checkDeath();
    bool 		checkWall();
    bool 		checkHit();
    void 		manageFruits();
    void 		eatFruit();
    void 		feedSnake();
    void 		spawnFruit();
    void 		initFruits();
    void 		checkFruits();
    virtual const std::string&	getConfigPath() const;

  public:
			Nibbler(uint16_t const width = 29,
			        uint16_t const height = 31);
			~Nibbler();
    /* Inherited from IGame */
    virtual const std::string& getName() const;
    virtual void	setInput(InputType);
    virtual void	play();
    virtual void 	start();
    virtual void 	stop();

    /* Inherited from AGame */
    virtual void 	moveUp() override;
    virtual void 	moveDown() override;
    virtual void 	moveLeft() override;
    virtual void 	moveRight() override;
};
}
#endif			/* !NIBBLER_H */
