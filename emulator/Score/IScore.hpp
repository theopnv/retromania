#ifndef			ISCORE_H
# define		ISCORE_H

# include		<iostream>
# include		<vector>

namespace retromania
{

class			IScore
{
  public:
    virtual		~IScore() {}
    virtual int		getValue() const = 0;
    virtual void	setValue(const int score) = 0;
};

}


#endif			/* !ISCORE_H */
