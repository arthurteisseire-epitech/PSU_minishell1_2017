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
SRC     =	$(DSRC)main.c \
		$(DSRC)mysh.c \
		$(DSRC)get_next_line.c \
		$(DSRC)run.c \
		$(DSRC)exec_cmd.c \
		$(DSRC)get_var_content.c \
		$(DSRC)count_args.c \
		$(DSRC)free_args.c \
		$(DSPLIT)split.c \
		$(DSPLIT)count_words.c \
		$(DSPLIT)get_next_word.c \
		$(DSPLIT)in_str.c \
		$(DSPLIT)len_first_word.c \
		$(DSPLIT)my_strncpy.c \
		$(DSPLIT)skip_first_flags.c \
		$(DENV)find_env.c \
		$(DENV)env.c \
		$(DENV)lk_list.c \
		$(DENV)free_list.c \
		$(DBUILTS)cd.c \
		$(DBUILTS)exec_builtins.c
CFLAGS	=	-Wall -W -Wextra -I$(INC) -g
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
