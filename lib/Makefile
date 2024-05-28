##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Lib Makefile
##

NAME	=	mylib.a

INCLUDE	=	../include/

FUNCS 	=	$(addprefix funcs/,	\
			str_to_word_array.c 	\
			free_array.c 	\
			arraylen.c 	\
			file_to_array.c 	\
			clean_str.c 	\
			is_str_digit.c 	\
			is_str_float.c 	\
			my_strlen_delim.c 	\
			) 	\

MATHS 	=	$(addprefix maths/,	\
			deg_to_rad.c	\
			rad_to_deg.c 	\
			get_deg.c 	\
			)	\

SRC		=	$(FUNCS) 	\
			$(MATHS)

CC	?=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS	=	-Wall -Wextra

OBJ	=	$(SRC:.c=.o)

DEBUG 	=	-g3

ASAN 	=	-fsanitize=address

all: $(NAME)

$(NAME):	$(OBJ)
		$(AR) rcs $(NAME) $(OBJ) && cp $(NAME) ../

clean:
		$(RM) $(OBJ)	\

fclean: clean
		$(RM) $(NAME)	\
		$(RM) ../$(NAME)

re: fclean all

debug:	$(CFLAGS) += $(DEBUG)
debug:	$(NAME)

asan:	$(CFLAGS) += $(ASAN)
asan: 	$(NAME)

.PHONY: all clean fclean re debug asan
