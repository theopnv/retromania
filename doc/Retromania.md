```
______     _              ___  ___            _
| ___ \   | |             |  \/  |           (_)
| |_/ /___| |_ _ __ ___   | .  . | __ _ _ __  _  __ _
|    // _ \ __| '__/ _ \  | |\/| |/ _` | '_ \| |/ _` |
| |\ \  __/ |_| | | (_) | | |  | | (_| | | | | | (_| |
\_| \_\___|\__|_|  \___/  \_|  |_/\__,_|_| |_|_|\__,_|

```
Project realised by Theo Penavaire & P.M. in 2017.
Interfaces were written following a pattern so that games and graphic libraries can be shared.

General - How to write a library
----------------------

You must create a class representing your library and inheriting the IGame interface if it's a game library (located in `emulator/IGame.hpp`), or from the
IGraphic interface if it's a graphical library (located in `emulator/IGraphic.hpp`).
Keep in mind that your library will entirely be abstracted through the interfaces.
It must have several mandatory parts :
- An entry point : The dynamic loader module will get an instance of the
library through it. It must follow this pattern :
```
extern "C"
{
    IGraphic	*entryPoint()
    {
      return new <Your Library>();
    }
}
```
- The initialization stuff of your library must be located in its constructor.
- You must also call the closing functions of your library , and free its variables in its destructor.

How to write a game library
----------------------
All games must be located in the `games/` folder.
The games are abstracted through the AGame class (`emulator/Game/AGame`). There are
several methods that can be useful in it, and will prevent you from writing them again.

There are mandatory virtual functions that you have to implement. They are explained in detail in the IGame markdown documentation file.

How to write a graphical library
----------------------
All graphical librariries must be located in the `lib/` folder.

There are mandatory virtual functions that you have to implement. They are explained in detail in the IGraphic markdown documentation file.

We strongly recommand to order your folder like this, to be coherent with our
libraries architecture :

```

lib
 |-- <yourLib>
	  |-- ressources		// Fonts, images, etc.
	  <yourLib>.hpp			// Class header
	  <yourLib>.cpp			// Ctor, Dtor, main functions
	  Init.cpp			// Initialisation functions called in ctor
	  Accessor.cpp			// Getters and Setters
	  Graphic.cpp			// Window, Blit, Display management
	  Makefile			// Must create the library

```
