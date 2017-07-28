#ifndef			ASTAR_H
# define		ASTAR_H

# include		<iostream>
# include		<vector>
# include		"AStarTypes.hpp"

namespace astar
{

class			AStar
{
  public:
    struct	Pos
    {
      int	y;
      int	x;
    };

  private:
    struct	Cell
    {
      int	F;
      int	G;
      int	H;
      Pos	cell;
      Cell 	*parent;
    };

    struct		CellTab
    {
      int		idx;
      std::vector<Cell>	array;
    };

  private:

    Pos		_target;
    int			_lastOut;
    Map		_map;
    CellTab		_close;
    CellTab		_open;
    path_t		_path;

    int			calcLower() const;
    void 		updateArrays(const Pos);
    void 		addIn();
    int			getI(int const, int const) const;
    int			getX(int const) const;
    int			getY(int const) const;
    void 		updateArrays(const int);
    bool		endCondition();
    bool		inArray(Pos const &) const;
    void 		updateDistances(const Pos);
    void 		flushPath();
    Cell 		*initParent();
  public:
			AStar(const int pos,
			      const int target,
			      const Map &map);
			~AStar();
    const path_t&	getPath();
};

bool		operator==(const AStar::Pos &,
			   const AStar::Pos &);
}
#endif			/* !ASTAR_H */
