#ifndef			FILE_HANDLER_EXCEPTION_HPP
# define		FILE_HANDLER_EXCEPTION_HPP

# include		"Exception.hpp"

namespace exception
{

class			FileHandlerException : public ProgException
{

  public:
			FileHandlerException(const std::string& e) throw();
			FileHandlerException() throw();
    virtual		~FileHandlerException() throw();

};

}

#endif			/* FILE_HANDLER_EXCEPTION_HPP */