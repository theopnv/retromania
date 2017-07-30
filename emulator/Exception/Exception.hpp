#ifndef			EXCEPTION_HPP
# define		EXCEPTION_HPP

# include		<exception>
# include		<string>

namespace		exception
{

class			ProgException
{
  private:
    std::string		_message;

  public:
			ProgException(const std::string& e) throw();
			ProgException() throw();
    virtual		~ProgException() throw();
    virtual const char	*what() const throw();
};

}

#endif			/* EXCEPTION_HPP */
