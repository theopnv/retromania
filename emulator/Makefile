
GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
CYAN		=	\033[0;36m
DEF		=	\033[0m

CC		=	g++
RM		=	rm -rf
NAME		=	../retro-station
CPPFLAGS	=	-W -Wall -Wextra -Werror -std=c++14 $(INC) -ldl -g
INC		=	-IGraphic			\
			-IGame 				\
			-ICore				\
			-IDLLoader			\
			-IFileHandler			\
			-IJsonParser			\
			-IScore				\
			-IException			\
			-I.

DLLOADER_DIR	=	DLLoader/
FILEHANDLER_DIR	=	FileHandler/
JSON_PARSER_DIR	=	JsonParser/
EXCEPTION_DIR	=	Exception/
SCORE_DIR	=	Score/
DIR		=	Core/
OBJS		=	$(SRCS:.cpp=.o)

SRCS		=	main.cpp				\
								\
			${DLLOADER_DIR}DLLoader.cpp		\
			${DLLOADER_DIR}DLLoaderException.cpp	\
								\
			${FILEHANDLER_DIR}FileHandler.cpp	\
								\
			${JSON_PARSER_DIR}JsonParser.cpp	\
								\
			${SCORE_DIR}Score.cpp			\
								\
			${EXCEPTION_DIR}Exception.cpp		\
								\
			${DIR}Init.cpp				\
			${DIR}Mainloop.cpp			\
			${DIR}Menu.cpp

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo -e "Building core executable.."
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo -e "$(GREEN)Executable file built$(DEF)\n"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
