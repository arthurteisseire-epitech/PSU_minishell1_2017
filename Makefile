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
DSPLIT	=	$(DSRC)split/
DENV	=	$(DSRC)env/
DBUILTS	=	$(DSRC)builtins/
DMYSH	=	$(DSRC)mysh/
DARGS	=	$(DSRC)args/
SRC     =	$(DSRC)main.c \
		$(DMYSH)mysh.c \
		$(DMYSH)get_next_line.c \
		$(DMYSH)run.c \
		$(DMYSH)exec_cmd.c \
		$(DARGS)count_args.c \
		$(DARGS)my_perror.c \
		$(DARGS)free_args.c \
		$(DSPLIT)split.c \
		$(DSPLIT)count_words.c \
		$(DSPLIT)get_next_word.c \
		$(DSPLIT)in_str.c \
		$(DSPLIT)len_first_word.c \
		$(DSPLIT)my_strncpy.c \
		$(DSPLIT)skip_first_flags.c \
		$(DENV)env.c \
		$(DENV)lk_list.c \
		$(DENV)free_env.c \
		$(DENV)head.c \
		$(DBUILTS)cd.c \
		$(DBUILTS)exec_builtins.c
CFLAGS	+=	-Wall -W -Wextra -I$(INC)
OBJ	=	$(SRC:.c=.o)
NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

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
