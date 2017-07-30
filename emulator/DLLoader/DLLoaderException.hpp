#ifndef			DLLOADER_EXCEPTION_HPP
# define		DLLOADER_EXCEPTION_HPP

# include		"Exception.hpp"

namespace exception
{

class			DLLoaderException : public ProgException
{

  public:
			DLLoaderException(const std::string& e) throw();
			DLLoaderException() throw();
    virtual		~DLLoaderException() throw();

};

}

#endif			/* DLLOADER_EXCEPTION_HPP */