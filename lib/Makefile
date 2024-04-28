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
			clean_str.c 	\
			is_str_digit.c 	\
			is_str_float.c 	\
			my_strlen_delim.c 	\
			) 	\

CC	?=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS	=	-Wall -Wextra

OBJ	=	$(SRC:.c=.o)

DEBUG 	=	-g3

ASAN 	=	-fsanitize=address

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

debug:	$(CFLAGS) += $(DEBUG)
debug:	$(NAME)

asan:	$(CFLAGS) += $(ASAN)
asan: 	$(NAME)

.PHONY: all clean fclean re debug asan
