#ifndef			SCORE_H
# define		SCORE_H

# include		"IScore.hpp"

namespace retromania
{

class			Score : public IScore
{
  private:
    int			_value;
  public:
			Score();
			~Score();
    virtual int		getValue() const;
    virtual void 	setValue(const int);
};

}

#endif			/* !SCORE_H */
