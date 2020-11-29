##
## EPITECH PROJECT, 2019
## epi
## File description:
## Makefile
##

NAME		=		my_hunter

SRC			=		src/main/main.c								\
					src/initialization/core_init.c				\
					src/initialization/cursor_init.c			\
					src/initialization/entity_init.c			\
					src/initialization/game_init.c				\
					src/initialization/hud_init.c				\
					src/initialization/particle_init.c			\
					src/initialization/hud_turtle_init.c		\
					src/game_loop/loop.c						\
					src/game_loop/round_type/rt_bounce.c		\
					src/game_loop/round_type/rt_ghost.c			\
					src/game_loop/round_type/rt_statue.c		\
					src/game_loop/round_type/index.c			\
					src/game_loop/end_round.c					\
					src/game_loop/game_over.c					\
					src/game_loop/hud_display.c					\
					src/game_loop/hud_turtle_display.c			\
					src/game_loop/cursor_display.c				\
					src/tool/tool_func.c						\
					src/tool/randomizer.c						\
					src/destroy/game_destroy.c

OBJ			=		$(SRC:%c=%o)

CC			=		gcc

CFLAGS		=		-I./include -W -Wall -Wextra -pedantic -Wshadow

LDFLAGS		=		-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lmy -L./lib

$(NAME)		:		$(OBJ)
					make -C ./lib
					$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all			:		$(NAME)

clean		:
					rm -f $(OBJ)
					make -C ./lib fclean

fclean		:		clean
					make -C ./lib fclean
					rm -f $(NAME)

debug		:		CFLAGS += -g
debug		:		re

re 			:		fclean all
