# Makefile for LIBLAPIN

GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
DEF		=	\033[0m

ROOT		=	../../
EMULATOR_DIR	=	${ROOT}emulator/

CC		=	g++
RM		=	rm -rf
NAME		=	../lib_liblapin.so
CPPFLAGS	=	-W -Wall -Wextra -Werror -std=c++14 $(INC) -g
LFLAGS		=	-fPIC -shared
INC		=	-I${EMULATOR_DIR}Graphic/			\
			-I${EMULATOR_DIR}				\
			-I/home/${USER}/.froot/include

LIBLAPIN_FLAGS  =  	-L/home/${USER}/.froot/lib		\
			-llapin -lsfml-graphics -lsfml-audio	\
			-lsfml-window -lsfml-system -lstdc++	\
			-lm -ldl -lpthread

COMMON_SRC	=	${EMULATOR_DIR}Graphic/AGraphic.cpp		\

SRCS		=	$(COMMON_SRC)				\
			LibLapin.cpp				\
			Init.cpp				\
			Accessor.cpp				\
			Graphic.cpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo -e "Building LibLapin library"
			$(CC) $(CPPFLAGS) $(SRCS) $(LIBLAPIN_FLAGS) $(LFLAGS) -o $(NAME)
			@echo -e "$(GREEN)LibLapin library created in graphic/\n$(DEF)"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
