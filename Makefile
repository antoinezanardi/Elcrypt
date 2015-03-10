##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Sun Mar  1 15:48:03 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra -pedantic -ansi
endif

LIB_PA	=	./lib/my/

NAME	=	elcrypt

SRCS	=	main.c \
		error.c \
		fc_base.c \
		fc_str.c \
		init_parsing.c \
		parsing.c \
		fill_data.c \
		fill_union.c \
		get_key.c \
		crypt.c \
		write_file.c \
		get_keyv2.c \
		cryptv2.c

OBJS	=	$(SRCS:.c=.o)

INC	=	-I include/

CFLAGS	+=	$(INC)


all: $(NAME)

$(NAME): $(OBJS)
	cc -Wall $(OBJS) $(INC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all
