#ifndef			SCORE_H
# define		SCORE_H

namespace retromania
{

class			Score
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
