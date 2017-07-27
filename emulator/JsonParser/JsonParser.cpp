#include "JsonParser.hpp"

namespace retromania
{

JsonParser::JsonParser(std::string const &path)
{
  _fileHandler = std::make_shared<FileHandler>(path);
  initColors();
}

JsonParser::~JsonParser()
{
}

const Sptr_t<conf_t> JsonParser::getConfig(AGame::tileIDTab_t &grammar)
{
  std::string	line;
  aff_t		aff;
  TileID	tileID = 0;
  size_t	tileCompleted = 0;
  Sptr_t<conf_t>	config = std::make_shared<conf_t>();

  do {
    line = _fileHandler->getLine();

    char	front = line.front();
    if (isalpha(front)) {
      tileID = grammar[line];
      ++tileCompleted;
    } else if (front == '\t') {
      if (line[1] == '0') {
	aff.sprite = line.substr(3);
	++tileCompleted;
      } else if (line[1] == '1') {
	aff.color = _colors[line.substr(3)];
	++tileCompleted;
      }
    }
    if (tileCompleted == 3) {
      config->insert(std::make_pair(tileID, aff));
      tileCompleted = 0;
    }
  } while (!line.empty());
  return config;
}

void 		JsonParser::initColors()
{
  _colors.insert(std::make_pair("BLUE", _BLUE));
  _colors.insert(std::make_pair("YELLOW", _YELLOW));
  _colors.insert(std::make_pair("RED", _RED));
  _colors.insert(std::make_pair("CYAN", _CYAN));
  _colors.insert(std::make_pair("PINK", _PINK));
  _colors.insert(std::make_pair("ORANGE", _ORANGE));
  _colors.insert(std::make_pair("GREEN", _GREEN));
  _colors.insert(std::make_pair("GREY", _GREY));
  _colors.insert(std::make_pair("BLACK", _BLACK));
}

}
