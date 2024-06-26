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

GAME_FUNCS 	=	$(addprefix funcs/,	\
				check_settings.c 	\
				get_map.c 	\
				get_data.c 	\
				get_settings.c 	\
				get_bindings.c 	\
				)	\

GAME_INITS 	=	$(addprefix inits/,	\
				init_game.c 	\
				init_rc_mode.c 	\
				)	\

RAY_CASTING	=	$(addprefix ray_casting/,	\
				$(addprefix display/,	\
				draw_map.c 	\
				draw_player.c 	\
				draw_rays.c	\
				display_rc.c 	\
				)	\
				$(addprefix gameplay/,	\
				get_collisions.c 	\
				player_movement.c \
				player_interaction.c 	\
				)	\
				ray_casting.c 	\
				)	\

SRC		=	$(addprefix src/,	\
			$(GAME_FUNCS)	\
			$(GAME_INITS)	\
			$(RAY_CASTING)	\
			display.c 	\
			events.c 	\
			main.c	\
			)	\

CC		?=	gcc

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS 		=	-Wall -Wextra

OBJ		=	$(SRC:.c=.o)

DEBUG 	=	-g3

ASAN 	=	-fsanitize=address

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

debug:	$(CFLAGS) += $(DEBUG)
debug:	$(NAME)

asan:	$(CFLAGS) += $(ASAN)
asan: 	$(NAME)

.PHONY: all clean fclean re debug asan
