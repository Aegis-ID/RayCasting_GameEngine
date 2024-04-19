##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Base Makefile
##

NAME		=	DieAndRetry

INCLUDE 	=	./include/

LIB		=	mylib.a

SUBDIRS		=	lib/

SRC		=	$(addprefix src/,	\
			main.c	\
			)	\

CC		?=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS 		=	-Wall -Wextra

OBJ		=	$(SRC:.c=.o)

#Additional Libraries
CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lGL -lcsfml-audio
MATHS		=	-lm

all: $(NAME)

$(NAME):	CFLAGS += $(CSFML)
$(NAME):	$(OBJ)
		$(MAKE) -C $(SUBDIRS) all
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(CSFML) $(MATHS)

clean:
		$(MAKE) -C $(SUBDIRS) clean
		$(RM) $(OBJ)
		$(RM) *log

fclean: clean
		$(MAKE) -C $(SUBDIRS) fclean
		$(RM) $(NAME)

re: fclean all
	$(MAKE) clean
	$(MAKE) -C $(SUBDIRS) re

debug:	CFLAGS += -g
debug:	$(MAKE) -C $(SUBDIRS) debug
debug:	re

asan:	CC = clang -fsanitize=address
asan:	$(MAKE) -C $(SUBDIRS) asan
asan: 	re

.PHONY: all clean fclean re debug asan
