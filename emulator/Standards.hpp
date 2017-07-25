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
typedef struct		map_s
{
  uint16_t		width;
  uint16_t		height;
  std::vector<TileID>	tiles;
}			map_t;

/*
** Structure holding the rendering of a specific tile for each game.
** Each graphical library must first try to display it with a sprite, if it
** cannot, it will display it with a color.
*/

typedef struct		aff_s
{
  std::string		sprite;		/* High priority */
  ColorType		color;		/* Low Priority */
}			aff_t;

/*
** Structure holding a position in the map.
*/

typedef struct		pos_s
{
  int			y;
  int			x;
}			pos_t;

typedef std::map<TileID, aff_t>		conf_t;

}

#endif /* STANDARDS_H_ */
