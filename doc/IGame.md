IGame
----------------------

Your game library must inherit from the IGame interface. The following functions will be called by the emulator.


    virtual std::string const	&getName() const = 0;

Returns the game name.

    virtual void		setInput(InputType) = 0;

Takes an input from the InputType enum (cf. `Standard.md`), and stock it in an internal variable.

    virtual conf_t const	*getConfig() const = 0;

Returns the configuration map, holding as key, a TileType (e.g WALL, PACMAN, etc), and as values, a sprite, and a color, representing this TileType.

    virtual IScore const	*getScore() const = 0;

Returns an int representing the score.

    virtual map_t const		*getMap() const = 0;

Returns the board game, actualised at each turn. Cf. `Standard.md` to know what is a map_t.

    virtual StateType		getState() const = 0;

Returns the state of the game (cf `Standard.md`).

    virtual start() = 0;

Starts the game.

    virtual stop() = 0;

Stops the game.
