#ifndef			IGRAPHIC_H
# define		IGRAPHIC_H

# include		<iostream>
# include		"Standards.hpp"

namespace retromania
{

class			IGraphic
{
  public:
    virtual		~IGraphic() {}

    /*
    ** Return LibName
    */
    virtual std::string const	&getName() const = 0;

    /*
    ** Get pressed key internally, return computed InputType
    */
    virtual InputType	getInput() const = 0;

    /*
    ** Create a window (!= from the constructor)
    */
    virtual void 	createWindow() = 0;

    /*
    ** Quit the window
    */
    virtual void 	quitWindow() = 0;

    /*
    ** Take the current game config as argument, assign it to an internal variable
    */
    virtual void	setConfig(conf_t const *config) = 0;

    /*
    ** Save graphical informations in memory.
    */
    virtual void	blitText(std::string const &text,
				 retromania::pos_t const &pos,
				 int const fontSize,
				 ColorType const color) = 0;

    /*
    ** Refresh the screen. If called in the menu, there's no need for a map, so
    ** it's set to null. When called during a game execution, the game map is passed
    */
    virtual void	display(map_t const *map = nullptr) = 0;
};
}
#endif			/* !IGRAPHIC */
