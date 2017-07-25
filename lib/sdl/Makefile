# Makefile for SDL

GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
DEF		=	\033[0m

ROOT		=	../../
EMULATOR_DIR	=	${ROOT}emulator/

CC		=	g++
RM		=	rm -rf
NAME		=	../lib_sdl.so
CPPFLAGS	=	-W -Wall -Wextra -Werror -std=c++14 	\
			-lSDL2 -lSDL2_image -lSDL2_ttf		\
			$(shell sdl2-config --cflags --libs)	\
			$(INC)
LFLAGS		=	-fpic -shared
INC		=	-I${EMULATOR_DIR}Graphic/			\
			-I${EMULATOR_DIR}

COMMON_SRC	=	${EMULATOR_DIR}Graphic/AGraphic.cpp

SRCS		=	$(COMMON_SRC)				\
			SDL.cpp					\
			Init.cpp				\
			Accessor.cpp				\
			Graphic.cpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo -e "Building SDL library"
			$(CC) $(LFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)
			@echo -e "$(GREEN)SDL library created in lib/\n$(DEF)"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
