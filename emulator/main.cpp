#include <sys/stat.h>
#include "Emulator.hpp"


void		usage(char *bin)
{
  std::cerr << "Usage: "
	    << bin
	    << " <path/to/graphical/library>"
	    << std::endl
	    << std::endl
	    << "Enter a fabulous revival of the 80's through this retro game emulator !"
	    << std::endl
	    << "There must be compatible (.so files) games and graphical librairies,"
	    << " respectively in games/ and graphic/ directories."
	    << std::endl;
}

bool		checkArgs(int ac, char **av)
{
  struct stat	buffer;

  if (ac != 2 || stat(av[1], &buffer) != 0) {
    usage(av[0]);
    return false;
  }
  return true;
}

int		main(int ac, char **av)
{
  if (!checkArgs(ac, av)) {
    return (FAILURE);
  }
  retromania::Emulator	emulator = retromania::Emulator(av[1]);

  emulator.mainloop();
  return (SUCCESS);
}


