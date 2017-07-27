#ifndef			SDL_H
# define		SDL_H

# include		<map>
# include		<SDL2/SDL.h>
# include		<SDL2/SDL_ttf.h>
# include		<SDL2/SDL_image.h>
# include		"AGraphic.hpp"

namespace retromania
{

class			SDL : public AGraphic
{
  typedef std::map<SDL_Keycode, InputType>	inputTab_t;
  typedef std::map<ColorType, SDL_Color>	colorTab_t;

  private:
   static const std::string	_FONT_PATH;
   static const size_t		_UNIT;
   static const std::string	_NAME;

    SDL_Window		*_window;
    SDL_Renderer	*_renderer;
    inputTab_t		_inputTab;
    colorTab_t		_colorTab;

    void		initSDL();
    void		initTTF();
    void 		initConfig();
    void		initInputTab();
    void		initColorTab();
    void		blitBackground() const;
  public:
			SDL();
			~SDL();

    virtual InputType	getInput() const;
    virtual std::string const	&getName() const;

    virtual void 	createWindow();
    virtual void 	quitWindow();
    virtual void	blitTile(const int, retromania::pos_t &);
    virtual void	blitText(std::string const &,
				 retromania::pos_t const &,
				 int const,
				 ColorType const);
    virtual void 	display(Sptr_t<map_t> const map = nullptr);
};
}
#endif			/* !SDL_H */
