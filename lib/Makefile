##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Lib Makefile
##

NAME	=	mylib.a

INCLUDE	=	../include/

SRC		=	$(addprefix maths/,	\
			deg_to_rad.c	\
			rad_to_deg.c 	\
			get_deg.c 	\
			)	\
			$(addprefix funcs/,	\
			str_to_word_array.c 	\
			free_array.c 	\
			arraylen.c 	\
			file_to_array.c 	\
			) 	\

CC	?=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS	=	-Wall -Wextra

OBJ	=	$(SRC:.c=.o)

#Additional Libraries
CSFML		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
MATHS		=	-lm

all: $(NAME)

$(NAME):	$(OBJ)
		$(AR) rcs $(NAME) $(OBJ) $(MATHS) && cp $(NAME) ../

clean:
		$(RM) $(OBJ)	\

fclean: clean
		$(RM) $(NAME)	\
		$(RM) ../$(NAME)	\

re: fclean all

debug:	CFLAGS += -g3
debug:	$(NAME)

asan:	CC = clang -fsanitize=address
asan: 	$(NAME)

.PHONY: all clean fclean re debug asan
