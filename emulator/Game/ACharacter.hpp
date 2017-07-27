#ifndef			ACHARACTER_H
# define		ACHARACTER_H

# include		"Standards.hpp"

namespace retromania
{

class			ACharacter
{
  public:
    typedef std::vector<int>	pos_t;
    typedef enum	dir_e
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    }			dir_t;

  protected:
    int			_id;
    std::string		_name;
    pos_t		_pos;
    dir_t		_dir;

  public:

			ACharacter();
			ACharacter(const pos_t pos,
				   const int id,
				   const std::string &name);
			~ACharacter();
    void		setId(const int);
    void		setName(const std::string &);
    void		setPosition(const pos_t);
    void		setDirection(const dir_t &);
    void		setTarget(const int);
    int			getId() const;
    std::string const &	getName() const;
    dir_t		getDirection() const;
    pos_t		getPosition() const;
    int			getPositionAt(const int) const;
    int			getTarget() const;
};

}

#endif			/* !ACHARACTER_H */
