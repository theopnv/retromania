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
  using inputTab_t	= std::map<SDL_Keycode, InputType>;
  using colorTab_t	= std::map<ColorType, SDL_Color>;

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
    virtual const std::string&	getName() const;

    virtual void 	createWindow();
    virtual void 	quitWindow();
    virtual void	blitTile(const int, retromania::Pos &);
    virtual void	blitText(std::string const &,
				 retromania::Pos const &,
				 int const,
				 ColorType const);
    virtual void 	display(Sptr_t<Map> const map = nullptr);
};
}
#endif			/* !SDL_H */
