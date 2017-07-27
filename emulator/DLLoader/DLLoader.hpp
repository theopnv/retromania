#ifndef			DLLOADER_H
# define		DLLOADER_H

# include		<iostream>
# include		<dlfcn.h>
# include		<memory>

template <class T>
using Sptr_t		= std::shared_ptr<T>;

/*
** Handles the loading and closing of a dynamic shared library.
*/
template <class T>
class			DLLoader
{
  private:

    void		*_handle;
    Sptr_t<T>		_dynLib;
    std::string		_entryPoint;
    void		*getErr(const char *err);

  public:
			DLLoader(std::string const &entryPoint = "entryPoint");
			~DLLoader();
    Sptr_t<T>		getInstance(std::string const &dynLib);
    void		*closeInstance();
    static bool		isDSOFile(std::string const &path);
};


#endif		/* !DLLOADER_H */
