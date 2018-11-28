
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

compil:	$(SRC:.c=.o)
	$(CC) -o $(NAME) -lm 102architects.o $(CFLAGS)

clean:
	$(RM) 102architects.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

PHONY:	re all clean fclean valgrind
