##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC	=	$(realpath src)/
INC	=	$(realpath include)
DLIB	=	$(realpath lib/my)/
DTESTS	=	$(realpath tests)/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
DTOOLS	=	$(DSRC)tools/
SRC     =	$(DSRC)main.c \
		$(DSRC)mysh.c \
		$(DSRC)get_next_line.c \
		$(DTOOLS)split.c
CFLAGS	=	-Wall -W -Wextra -I$(INC) -ggdb3
OBJ	=	$(SRC:.c=.o)
NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	make clean -C $(DLIB)
	make clean -C $(DTESTS)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DLIB)
	make fclean -C $(DTESTS)
	rm -f $(NAME)

re: fclean all
	make clean

test_run: re
	make test_run -C $(DTESTS)
