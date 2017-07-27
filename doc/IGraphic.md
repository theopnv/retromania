IGraphic
----------------------

Your graphic library must inherit from the [IGraphic interface](../emulator/Graphic/IGraphic.hpp). The following functions will be called by the emulator.

    virtual std::string const	&getName() const = 0;

Returns the name of the graphical library

    virtual InputType		getInput() const = 0;

Returns the input, taken from the InputType enumeration (cf [Standards file](../emulator/Standards.hpp)).

    virtual void		createWindow() = 0;

Creates a window.

    virtual void 		quitWindow() = 0;

Quits the window.

    virtual void 		setConfig(conf_t const *) = 0;

Sets the configuration map, previously returned from the current game. This way, the graphical library knows exactly how to display each tile of the map.

    virtual void 		blitText(std::string const&, retromania::Position const &, int const, ColorType const) = 0;

Takes, respectively as arguments : the message to display, the position, the size of the font, and the color.

    virtual void 		display(const std::shared_ptr<map_t> map = nullptr) = 0;

Refresh the screen. If called from menu, there's no need for a map so nullptr is passed. When called during a game execution, the game map is passed.
