#ifndef			FILE_HANDLER_H
# define		FILE_HANDLER_H

# include		<fstream>
# include		"FileHandlerException.hpp"

namespace fileHandler
{

/*
** Handles operations relative to files : openning, reading, closing
*/
class			FileHandler
{
  private:
    std::string		_path;
    std::fstream	_file;
  public:
  			FileHandler(const std::string &,
				    const std::string & strerr = "Wrong file path");
			~FileHandler();
    std::string const &	getPath() const;
    std::string		getLine(const char delim = '\n');
};
}
#endif			/* !FILE_HANDLER_H */
