# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:56:39 by argomez           #+#    #+#              #
#    Updated: 2022/07/15 13:02:29 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define display_compilation 
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *     \e[96mCompilation Complete\e[0m     \e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[0m"
endef

define display_clean 
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *        \e[96mClean Complete        \e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[0m"
endef


NAME		=	so_long
NAME_B		=	.so_long

CC			=	gcc
CFLAGS		=	-g -Wall -Werror -Wextra
RM			=	rm -f

MADATORY	=	main.c						\
				change_matrix.c				\

BONUS		=	main.c						\
				change_matrix.c				\

SRC			=	errors.c					\

INITS		=	game_init.c					\
				map_init.c					\

MAPS		=	map_inspector.c				\
				check_map_symbols.c			\

IMPORTS		=	import_images.c				\
				import_chars.c				\
				import_collects.c			\
				import_escapes.c			\
				import_numbers.c			\
				import_sentinels.c			\
				import_tiles.c				\
				import_walls.c				\

DISPLAYS	=	open_window.c				\
				display_count.c				\
				put_image_entity.c			\

MOVES		=	move_entities.c				\
				able_to_move.c				\
				apply_case.c				\
				player_on_sentinel.c		\
				player_on_escape.c			\
				push_entity.c				\
				reset_case.c				\

PRINTS		=	print_collects.c			\
				print_escapes.c				\
				print_images.c				\
				print_images_2.c			\
				print_players.c				\
				print_sentinels.c			\
				print_tiles.c				\
				print_trees.c				\
				print_walls.c				\
	
CLEARS		=	clear_game.c				\
				clear_images.c				\

SRCS_MANDA	=	$(addprefix srcs/mandatory/, $(SRC))					\
				$(addprefix srcs/mandatory/inits/, $(INITS))			\
				$(addprefix srcs/mandatory/maps/, $(MAPS))				\
				$(addprefix srcs/mandatory/displays/, $(DISPLAYS))		\
				$(addprefix srcs/mandatory/clears/, $(CLEARS))			\
				$(addprefix srcs/mandatory/imports/, $(IMPORTS))		\
				$(addprefix srcs/mandatory/moves/, $(MOVES))			\
				$(addprefix srcs/mandatory/prints/, $(PRINTS))			\
				$(addprefix srcs/mandatory/, $(MADATORY))					\

SRCS_BONUS	=	$(addprefix srcs/bonus/, $(SRC))						\
				$(addprefix srcs/bonus/inits/, $(INITS))				\
				$(addprefix srcs/bonus/maps/, $(MAPS))					\
				$(addprefix srcs/bonus/displays/, $(DISPLAYS))			\
				$(addprefix srcs/bonus/clears/, $(CLEARS))				\
				$(addprefix srcs/bonus/imports/, $(IMPORTS))			\
				$(addprefix srcs/bonus/moves/, $(MOVES))				\
				$(addprefix srcs/bonus/prints/, $(PRINTS))				\
				$(addprefix srcs/bonus/, $(BONUS))						\


OBJ_MANDA	=	$(SRCS_MANDA:.c=.o)


OBJ_BONUS	=	$(SRCS_BONUS:.c=.o)

LIBFT		=	libft/libft.a

MINILIBX	=	minilibx-linux/libmlx_Linux.a

all: $(NAME)

.c.o: $(SRCS)
	@ $(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@ make -C libft --no-print-directory

$(MINILIBX):
	 @ make -C minilibx-linux --no-print-directory

libftfclean:
	@ make fclean -C libft --no-print-directory

minilibxclean:
	@ make clean -C minilibx-linux --no-print-directory

clearing:
	@ clear

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_MANDA)
	@ $(CC) $(CFLAGS) $(OBJ_MANDA) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft/libft.a -o $(NAME)
	$(display_compilation)

$(NAME_B): $(LIBFT) $(MINILIBX) $(OBJ_BONUS)
	@ $(CC) $(CFLAGS) $(OBJ_BONUS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft/libft.a -o $(NAME)
	@ touch $(NAME_B)
	$(display_compilation)

bonus:	$(NAME_B)

clean:
	@ $(RM) $(OBJ_MANDA) $(OBJ_BONUS) $(NAME_B)
	$(display_clean)

fclean:	clearing minilibxclean libftfclean clean
	@ $(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
