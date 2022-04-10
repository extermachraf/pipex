NAME = pipex
CC = cc
SRC = ft_findpath.c ft_pipex_utils.c ft_split.c ft_substr.c pipex.c 
FLAGS = -Wall -Wextra -Werror
ARG = -o

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) $(ARG) pipex

clean : 
	rm -f $(NAME)

fclean : clean

re: fclean all