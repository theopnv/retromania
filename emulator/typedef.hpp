#ifndef			TYPEDEF_H
# define		TYPEDEF_H

# include		<iostream>
# include		<vector>
# include		<memory>

# define SUCCESS	0
# define FAILURE	84

namespace retromania
{
  using StrTab_t	= std::vector<std::string>;

  template <class T>
  using Sptr_t		= std::shared_ptr<T>;
}

#endif			/* !TYPEDEF_H */
