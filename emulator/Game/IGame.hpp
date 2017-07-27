#ifndef				IGAME_H
# define			IGAME_H

# include			"Score.hpp"
# include			"IGraphic.hpp"
# include			"Standards.hpp"

namespace retromania
{

class				IGame
{
  public:

    virtual			~IGame() {}
    virtual const std::string&	getName() const = 0;
    virtual void		setInput(InputType) = 0;
    virtual const Score&	getScore() const = 0;
    virtual StateType		getState() const = 0;
    virtual void		start() = 0;
    virtual void		stop() = 0;
    virtual const Sptr_t<map_t>		getMap() const = 0;
    virtual const Sptr_t<conf_t>	getConfig() const = 0;

    virtual void		goUp() = 0;
    virtual void		goDown() = 0;
    virtual void		goLeft() = 0;
    virtual void		goRight() = 0;
    virtual void		goForward() = 0;
    virtual void		play() = 0;
};

}

#endif				/* !IGAME_H */
