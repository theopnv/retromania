#ifndef			ASTAR_TYPES_H
# define		ASTAR_TYPES_H

namespace retromania
{

typedef struct
{
  int			width;
  int			height;
  std::vector<bool>	map;
}			aMap_t;

typedef std::vector<int>	path_t;
}

#endif			/* !ASTAR_TYPES_H */
