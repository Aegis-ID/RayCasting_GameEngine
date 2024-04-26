##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Base Makefile
##

NAME		=	myrpg

INCLUDE 	=	./include/

LIB		=	mylib.a

SUBDIRS		=	lib/

SRC		=	$(addprefix src/,	\
			$(addprefix funcs/,	\
			get_map.c 	\
			)	\
			$(addprefix ray_casting/,	\
			draw_map.c 	\
			draw_rays.c	\
			draw_walls.c 	\
			ray_casting.c 	\
			)	\
			main.c	\
			display.c 	\
			events.c 	\
			)	\

CC		?=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS 		=	-Wall -Wextra

OBJ		=	$(SRC:.c=.o)

#Additional Libraries
CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
CSFML	+=	-lGL -lGLU
MATHS	=	-lm

all: $(NAME)

$(NAME):	CFLAGS += $(CSFML)
$(NAME):	$(OBJ)
		$(MAKE) -C $(SUBDIRS)
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(CSFML) $(MATHS)

clean:
		$(MAKE) -C $(SUBDIRS) clean
		$(RM) $(OBJ)
		$(RM) *log

fclean: clean
		$(MAKE) -C $(SUBDIRS) fclean
		$(RM) $(NAME)

re: fclean all
	$(MAKE) -C $(SUBDIRS) re
	$(MAKE)

debug:	CFLAGS += -g
debug:	$(MAKE) -C $(SUBDIRS) debug
debug:	$(NAME)

asan:	CC = clang -fsanitize=address
asan:	$(MAKE) -C $(SUBDIRS) asan
asan: 	$(NAME)

.PHONY: all clean fclean re debug asan
