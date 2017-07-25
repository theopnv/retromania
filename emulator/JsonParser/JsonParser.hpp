#ifndef			JSON_PARSER_H
# define		JSON_PARSER_H

# include		"IGraphic.hpp"
# include		"FileHandler.hpp"
# include		"AGame.hpp"

namespace retromania
{


class			JsonParser
{
  typedef std::unordered_map<std::string, ColorType>	colorTab_t;

  private:
    FileHandler		*_fileHandler;
    colorTab_t		_colors;

    void 		initColors();
  public:
			JsonParser(std::string const &path);
			~JsonParser();
    conf_t		*getConfig(AGame::tileIDTab_t &grammar);
};
}
#endif			/* !JSON_PARSER_H */
