#ifndef			ACHARACTER_H
# define		ACHARACTER_H

# include		"Standards.hpp"

namespace retromania
{

class			ACharacter
{
  public:
    using Pos		= std::vector<int>;

    enum		Dir
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

  protected:
    int			_id;
    std::string		_name;
    Pos			_pos;
    Dir			_dir;

  public:

			ACharacter();
			ACharacter(const Pos pos,
				   const int id,
				   const std::string &name);
			~ACharacter();
    void		setId(const int);
    void		setName(const std::string &);
    void		setPosition(const Pos);
    void		setDirection(const Dir &);
    void		setTarget(const int);
    int			getId() const;
    const std::string&	getName() const;
    Dir			getDirection() const;
    Pos			getPosition() const;
    int			getPositionAt(const int) const;
    int			getTarget() const;
};

}

#endif			/* !ACHARACTER_H */
