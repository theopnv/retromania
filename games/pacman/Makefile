# Makefile for LIBCACA

GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
DEF		=	\033[0m

ROOT		=	../../
EMULATOR_DIR	=	${ROOT}emulator/

CC		=	g++
RM		=	rm -rf
NAME		=	../lib_pacman.so
CPPFLAGS	=	-W -Wall -Wextra -Werror -std=c++14 $(INC) -g
LFLAGS		=	-fPIC -shared
INC		=	-I${EMULATOR_DIR}Game/			\
			-I${EMULATOR_DIR}Graphic/			\
			-I${EMULATOR_DIR}JsonParser/		\
			-I${EMULATOR_DIR}FileHandler/		\
			-I${EMULATOR_DIR}Score/			\
			-I${EMULATOR_DIR}				\
			-I${ASDIR}				\
			-I${GDIR}				\
			-I./

COMMON_SRC	=	${EMULATOR_DIR}Game/AGame.cpp		\
			${EMULATOR_DIR}Game/Actions.cpp		\
			${EMULATOR_DIR}Game/ACharacter.cpp		\
			${EMULATOR_DIR}JsonParser/JsonParser.cpp	\
			${EMULATOR_DIR}FileHandler/FileHandler.cpp	\
			${EMULATOR_DIR}Score/Score.cpp

GDIR		=	Ghost/
ASDIR		=	AStar/

SRCS		=	$(COMMON_SRC)				\
			Pacman.cpp				\
			Move.cpp				\
			Init.cpp				\
			Accessor.cpp				\
			Interaction.cpp				\
								\
			${GDIR}AGhost.cpp			\
			${GDIR}Blinky.cpp			\
			${GDIR}Inky.cpp				\
			${GDIR}Pinky.cpp			\
			${GDIR}Clyde.cpp			\
								\
			${ASDIR}AStar.cpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo -e "Building Pacman library"
			$(CC) $(LFLAGS) $(SRCS) $(CPPFLAGS) -o $(NAME)
			@echo -e "$(GREEN)Pacman library created in games/\n$(DEF)"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
