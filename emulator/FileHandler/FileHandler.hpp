#ifndef			FILE_HANDLER_H
# define		FILE_HANDLER_H

# include		<fstream>
# include		<dirent.h>
# include		<sys/types.h>
# include		"FileHandlerException.hpp"

namespace fileHandler
{

/*
** Handles operations relative to files : openning, reading, closing
*/
class			FileHandler
{
  public:
    enum		Type
    {
      UNDEFINED,
      FILE,
      DIR,
    };

  private:
    std::string		_path;
    Type		_type;
    std::fstream	_file;
    ::DIR		*_directory;
    struct dirent	*_currFileInDir;

  public:
  			FileHandler(const std::string& path = "",
				    const Type& = UNDEFINED);
			~FileHandler();
    std::string const &	getPath() const;
    void		open();
    void		setPath(const std::string& path);
    void		setType(const Type& type);
    std::string		getLine(const char delim = '\n');
    std::string		getCurrFileName();
};
}
#endif			/* !FILE_HANDLER_H */
