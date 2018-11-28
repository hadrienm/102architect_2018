
## EPITECH PROJECT, 2018
## Makefile
## File description:
## finalstumper
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra

NAME	= 102architect

SRC 	= 102architects.c

all:	compil

compil:	$(SRC)
	$(CC) -o $(NAME) -lm $(SRC) $(CFLAGS)

clean:
	$(RM) $(NAME)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

PHONY:	re all clean fclean valgrind
