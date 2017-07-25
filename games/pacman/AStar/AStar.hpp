#ifndef			ASTAR_H
# define		ASTAR_H

# include		<iostream>
# include		<vector>
# include		"AStarTypes.hpp"

namespace retromania
{

class			AStar
{
  public:
    typedef struct
    {
      int		y;
      int		x;
    }			coor_t;

  private:
    typedef struct	cell_s
    {
      int		F;
      int		G;
      int		H;
      coor_t		cell;
      struct cell_s 	*parent;
    }			cell_t;

    typedef struct
    {
      int			idx;
      std::vector<cell_t>	array;
    }				array_t;

  private:

    coor_t		_target;
    int			_lastOut;
    aMap_t		_map;
    array_t		_close;
    array_t		_open;
    path_t		_path;

    int			calcLower() const;
    void 		updateArrays(const coor_t);
    void 		addIn();
    int			getI(int const, int const) const;
    int			getX(int const) const;
    int			getY(int const) const;
    void 		updateArrays(const int);
    bool		endCondition();
    bool		inArray(coor_t const &) const;
    void 		updateDistances(const coor_t);
    void 		flushPath();
    cell_t 		*initParent();
  public:
			AStar(const int pos,
			      const int target,
			      const aMap_t &map);
			~AStar();
    path_t const	&getPath();
};

bool		operator==(const AStar::coor_t &,
			   const AStar::coor_t &);
}
#endif			/* !ASTAR_H */
