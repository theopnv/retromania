# Makefile for LIBCACA

GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
DEF		=	\033[0m

ROOT		=	../../
EMULATOR_DIR	=	${ROOT}emulator/

CC		=	g++ -g
RM		=	rm -rf
NAME		=	../lib_nibbler.so
CPPFLAGS	=	-W -Wall -Wextra -Werror -std=c++14 $(INC) -g
LFLAGS		=	-fpic -shared
INC		=	-I${EMULATOR_DIR}Game/			\
			-I${EMULATOR_DIR}Graphic/			\
			-I${EMULATOR_DIR}JsonParser/		\
			-I${EMULATOR_DIR}FileHandler/		\
			-I${EMULATOR_DIR}Score/			\
			-I${EMULATOR_DIR}

COMMON_SRC	=	${EMULATOR_DIR}Game/AGame.cpp		\
			${EMULATOR_DIR}Game/Actions.cpp		\
			${EMULATOR_DIR}Game/ACharacter.cpp		\
			${EMULATOR_DIR}JsonParser/JsonParser.cpp	\
			${EMULATOR_DIR}FileHandler/FileHandler.cpp	\
			${EMULATOR_DIR}Score/Score.cpp

SRCS		=	$(COMMON_SRC)				\
			Nibbler.cpp				\
			Move.cpp				\
			Init.cpp
OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo -e "Building Nibbler library"
			$(CC) $(LFLAGS) $(SRCS) $(CPPFLAGS) $(INC) -o $(NAME)
			@echo -e "$(GREEN)Nibbler library created in games/\n$(DEF)"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
