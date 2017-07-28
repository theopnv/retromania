#ifndef			ASTAR_TYPES_H
# define		ASTAR_TYPES_H

# include		<vector>

namespace astar
{

struct			Map
{
  int			width;
  int			height;
  std::vector<bool>	map;
};

using path_t		= std::vector<int>;

}

#endif			/* !ASTAR_TYPES_H */
