#ifndef			ARCADE_H
# define		ARCADE_H

# include		<map>
# include		"IGame.hpp"
# include		"Score.hpp"
# include		"IGraphic.hpp"
# include		"DLLoader.hpp"
# include		"typedef.hpp"

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
    template <class T>
    struct			lib_s
    {
      Sptr_t<T>			lib;
      Sptr_t<DLLoader<T>>	loader;
    };

    template <class T>
    using lib_t = lib_s<T>;
    template <class T>
    using libTab_t = std::vector<lib_t<T> >;

    using gameTab_t	= libTab_t<IGame>;
    using graphicTab_t	= libTab_t<IGraphic>;
    using scoreTab_t	= std::map<std::string, Sptr_t<Score>>;
    typedef void 	(Emulator::*aFp)();

    gameTab_t		_games;
    int			_idxGame;	/* Current game (index) */
    Sptr_t<IGame>	_currGame;	/* Equivalent to _games[_idxGame].lib */

    graphicTab_t	_graphics;
    int			_idxGraphic;	/* Current Graphic lib (index) */
    Sptr_t<IGraphic>	_currGraphic;	/* Equivalent to _graphic[_idxGraphic].lib */

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
    template <class T>
    void		openLibDir(std::string const &, libTab_t<T> &);
    template <class T>
    lib_t<T>		getLibInstance(std::string const &);
    void		whereIsCursor(int const);
    template <class T>
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
