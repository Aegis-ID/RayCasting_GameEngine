##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Base Makefile
##

NAME		=	my_game

INCLUDE 	=	./include/

LIB		=	mylib.a

SUBDIRS		=	lib/

TOOLS 	=	$(addprefix tools/, 	\
			get_time.c 	\
			get_fov.c 	\
			get_ratio.c 	\
			animations.c 	\
			get_rand_pos.c 	\
			sfmouse.c 	\
			sprite_tools.c 	\
			) 	\

INITS 	=	$(addprefix inits/, 	\
			init_settings.c 	\
			init_game.c 	\
			init_entities.c 	\
			init_graphics.c 	\
			init_gameplay.c 	\
			init_interface.c 	\
			init_map.c 	\
			) 	\

SETTINGS 	=	$(addprefix settings/, 	\
			check_settings.c 	\
			get_bindings.c 	\
			get_data.c 	\
			) 	\

ENTITIES 	=	$(addprefix entities/, 	\
			) 	\

GRAPHICS 	=	$(addprefix graphics/, 	\
			display_exploration.c 	\
			display_hud.c 	\
			display_minimap.c 	\
			draw_ray.c 	\
			ray_casting.c 	\
			) 	\

GAMEPLAY 	=	$(addprefix gameplay/, 	\
			collisions.c 	\
			interactions.c 	\
			movements.c 	\
			) 	\

INTERFACE 	=	$(addprefix interface/, 	\
			) 	\

SRC		=	$(addprefix src/,	\
			$(TOOLS)	\
			$(INITS)	\
			$(SETTINGS)	\
			$(ENTITIES)	\
			$(GRAPHICS)	\
			$(GAMEPLAY)	\
			$(INTERFACE)	\
			display.c 	\
			events.c 	\
			)	\
			main.c

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
		$(RM) $(OBJ)
		$(RM) *log
		$(MAKE) -C $(SUBDIRS) clean

fclean: clean
		$(RM) -r $(ASSETS)
		$(RM) $(NAME)
		$(MAKE) -C $(SUBDIRS) fclean

re: fclean all
	$(MAKE) -C $(SUBDIRS) re
	$(MAKE)

debug:	$(CFLAGS) += $(DEBUG)
debug:	$(NAME)

asan:	$(CFLAGS) += $(ASAN)
asan: 	$(NAME)

.PHONY: all clean fclean re debug asan
