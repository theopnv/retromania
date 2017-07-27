# Makefile for LIBCACA

GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
DEF		=	\033[0m

ROOT		=	../../
EMULATOR_DIR	=	${ROOT}emulator/

CC		=	g++
RM		=	rm -rf
NAME		=	../lib_libcaca.so
CPPFLAGS	=	-W -Wall -Wextra -Werror -std=c++14 $(INC) $(LIBCACA_FLAGS) -g
LFLAGS		=	-fPIC -shared
INC		=	-I${EMULATOR_DIR}Graphic/			\
			-I${EMULATOR_DIR}
LIBCACA_FLAGS	=	-lcaca

COMMON_SRC	=	${EMULATOR_DIR}Graphic/AGraphic.cpp

SRCS		=	LibCaca.cpp				\
			Init.cpp				\
			Accessor.cpp				\
			Graphic.cpp				\
			$(COMMON_SRC)

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo -e "Building LibCaca library"
			$(CC) $(LFLAGS) $(SRCS) $(CPPFLAGS) -o $(NAME)
			@echo -e "$(GREEN)Library LibCaca created in lib/\n$(DEF)"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
