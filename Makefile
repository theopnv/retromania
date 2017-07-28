## Main Makefile for Retromania
##
## Authors:
## P.M
## Theo Penavaire (@theo-pnv)
##

GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
DEF		=	\033[0m

NAME		=	retromania

EMULATOR_DIR	=	emulator/
GAME_DIR	=	games/
LIB_DIR		=	graphic/

all		:	$(NAME)

$(NAME)		:	liblapin sdl pacman nibbler libcaca exe
			@echo -e "$(GREEN)Emulator, librairies & games built and ready !$(DEF)\n"

exe		:
			make -sC ${EMULATOR_DIR}

libcaca	:
			make -sC ${LIB_DIR}libcaca

sdl		:
			make -sC ${LIB_DIR}sdl

liblapin	:
			make -sC ${LIB_DIR}liblapin

nibbler		:
			make -sC ${GAME_DIR}nibbler

pacman		:
			make -sC ${GAME_DIR}pacman

clean		:
			@echo -e "$(ORANGE)Cleaning object files$(DEF)"
			make clean -sC ${EMULATOR_DIR}
			make clean -sC ${LIB_DIR}libcaca
			make clean -sC ${LIB_DIR}sdl
			make clean -sC ${LIB_DIR}liblapin
			make clean -sC ${GAME_DIR}nibbler
			make clean -sC ${GAME_DIR}pacman

fclean		:	clean
			@echo -e "$(ORANGE)Cleaning binary and shared libraries$(DEF)"
			make fclean -sC ${EMULATOR_DIR}
			make fclean -sC ${LIB_DIR}libcaca
			make fclean -sC ${LIB_DIR}sdl
			make fclean -sC ${LIB_DIR}liblapin
			make fclean -sC ${GAME_DIR}nibbler
			make fclean -sC ${GAME_DIR}pacman

re		:	fclean all

.PHONY		:	all clean fclean re exe sdl libcaca liblapin nibbler pacman
