#ifndef			ARCADE_H
# define		ARCADE_H

# include		<map>
# include		"IGame.hpp"
# include		"Score.hpp"
# include		"IGraphic.hpp"
# include		"DLLoader.hpp"
# include		"main.hpp"

# define IS_MENU_KEY(k)	(k == ESC || k == TWO || k == THREE || k == FOUR	\
			 || k == FIVE || k == EIGHT || k == NINE)
namespace retromania
{

class			Emulator
{
  private:

    /*
    ** Object representing a dynamic library
    ** The lodaer is needed to close the instance when exiting
    */
    template <typename T>
    struct		lib_s
    {
      DLLoader<T>	*loader;
      T			*lib;
    };

    template <typename T>
    using lib_t = lib_s<T>;
    template <typename T>
    using libTab_t = std::vector<lib_t<T> >;

    typedef libTab_t<IGame>				gameTab_t;
    typedef libTab_t<IGraphic>				graphicTab_t;
    typedef std::map<std::string, IScore *>		scoreTab_t;
    typedef void 					(Emulator::*aFp)();

    gameTab_t		_games;
    int			_idxGame;	/* Current game (index) */
    IGame		*_currGame;	/* Equivalent to _games[_idxGame].lib */

    graphicTab_t	_graphics;
    int			_idxGraphic;	/* Current Graphic lib (index) */
    IGraphic		*_currGraphic;	/* Equivalent to _graphic[_idxGraphic].lib */

    std::string		_defaultLib;
    InputType		_input;		/* User Input */
    bool		_leaveEmulator;	/* Leave the retromania ? :'( */
    bool		_inMenu;	/* Player is in menu */
    int			_cursor;
    std::map<InputType, aFp>	_menuTab;
    StateType		_currGameState;
    scoreTab_t		_scoreTab;

  public:

			Emulator(std::string const &);
			~Emulator();
    void		mainloop();

  private:
    void 		initLibrairies(std::string const &);
    void 		initMenuTab();
    void 		initScore();
    void 		affMenu();
    void 		chooseLib();

    void		options();
    void		setLibraries();
    template <typename T>
    void		openLibDir(std::string const &, libTab_t<T> &);
    template <typename T>
    lib_t<T>		getLibInstance(std::string const &);
    void		whereIsCursor(int const);
    template <typename T>
    void 		switchLibrary(const int);
    void 		saveScore();
    void 		affScores();

    /* MENU */
    void 		leaveEmulator();
    void 		prevGraphic();
    void 		nextGraphic();
    void 		prevGame();
    void 		nextGame();
    void 		restartGame();
    void 		backToMenu();
};

}
#endif			/* !ARCADE_H */
