Standards
----------------------

To separate the logic of our game (IGame) from their display (IGraphic), we needed a set of protocols. See the [Standards file](../emulator/Standards.hpp) to see how it's implemented.

- Input (keyboard): InputType
- Color: ColorType
- State (of game): StateType

The game board (`Map`) is a vector of TileType (integers). Each map must be written and put in the game directory. There must also be a configuration file, linked to a configuration structure (`conf_t`), telling the graphical library how to display each type of tile.
