#ifndef STANDARDS_H_
# define STANDARDS_H_

# include <string>
# include <vector>
# include <map>

namespace retromania
{

enum	InputType
{
  UP,
  DOWN,
  LEFT,
  RIGHT,
  ESC,
  ENTER,
  SPACE,
  NONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  EIGHT,
  NINE
};

enum	ColorType
{
  _WHITE,
  _RED,
  _BLUE,
  _BLACK,
  _YELLOW,
  _ORANGE,
  _CYAN,
  _PINK,
  _GREEN,
  _GREY
};

enum	StateType
{
  OFF,
  ON,
  WIN,
  LOST,
    TRANSFORM
};

/*
** Structure holding the map.
*/

typedef int		TileID;
struct			Map
{
  uint16_t		width;
  uint16_t		height;
  std::vector<TileID>	tiles;
};

/*
** Structure holding the rendering of a specific tile for each game.
** Each graphical library must first try to display it with a sprite, if it
** cannot, it will display it with a color.
*/

struct		TileDisplay
{
  std::string	sprite;		/* High priority */
  ColorType	color;		/* Low Priority */
};

/*
** Structure holding a position in the map.
*/

struct	Pos
{
  int	y;
  int	x;
};

typedef std::map<TileID, TileDisplay>	conf_t;

}

#endif /* STANDARDS_H_ */
