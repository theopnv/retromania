#ifndef			DLLOADER_H
# define		DLLOADER_H

# include		<iostream>
# include		<dlfcn.h>

/*
** Handles the loading and closing of a dynamic shared library.
*/
namespace retromania
{

template <class T>
class			DLLoader
{
  private:

    void		*_handle;
    T			*_dynLib;
    std::string		_entryPoint;
    void		*getErr(const char *err);

  public:
			DLLoader(std::string const &entryPoint = "entryPoint");
			~DLLoader();
    T			*getInstance(std::string const &dynLib);
    void		*closeInstance();
    static bool		isDSOFile(std::string const &path);
};
}
#endif		/* !DLLOADER_H */
