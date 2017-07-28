#ifndef			JSON_PARSER_H
# define		JSON_PARSER_H

# include		"IGraphic.hpp"
# include		"FileHandler.hpp"
# include		"AGame.hpp"

namespace retromania
{

class			JsonParser
{
  using colorTab_t	= std::unordered_map<std::string, ColorType>;

  private:
    Sptr_t<FileHandler>	_fileHandler;
    colorTab_t		_colors;

    void 		initColors();
  public:
			JsonParser(std::string const &path);
			~JsonParser();
    const Sptr_t<conf_t>	getConfig(AGame::tileIDTab_t &grammar);
};

}

#endif			/* !JSON_PARSER_H */
