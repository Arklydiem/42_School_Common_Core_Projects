# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 09:33:06 by vnadal            #+#    #+#              #
#    Updated: 2023/02/10 14:50:38 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	=  --no-print-directory

NAME		=	cub3d

BONUS		=	.cub3d

FLAGS		=	-Wall -Wextra -Werror -g

CC			=	clang

RM			=	rm -rf

INCLUDE		=	-Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft/libft.a

PARSING		=	manage_file								\
				check_map_validity						\
				map_is_closed							\

DISPLAY		=	manage_display							\
				set_coordinates							\
				set_player_direction					\
				calculs									\
				frame_rate								\
				display_colors							\
				manage_keys								\
				move_player								\
				rotate_player							\
				load_images								\

DISPLAY_B	=	display_mini_map						\
				manage_mouse							\
				open_close_doors						\
				display_player_rotation					\

UTILS		=	save_texture							\
				check_empty_line						\
				check_texture							\
				skip_empty_lines						\
				check_arround_spaces					\
				check_inner_map							\
				check_multiple_char						\
				ft_extension							\
				ft_abs									\
				rgb_to_hexa_color						\
				define_base_colors						\
				exit_program							\
				find_texture							\
				check_commas_rgb						\

UTILS_B		=	check_doors								\
				check_images							\
				get_max_line							\

SRCS		=	./srcs/main.c							\
				./srcs/ft_error.c						\
				./srcs/free_program.c					\
				./srcs/init_datas.c						\
				$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING)))	\
				$(addsuffix .c, $(addprefix srcs/display/, $(DISPLAY)))	\
				$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS)))		\

SRCS_B		=	./srcs_bonus/main_bonus.c																\
				./srcs_bonus/ft_error_bonus.c															\
				./srcs_bonus/free_program_bonus.c														\
				./srcs_bonus/init_datas_bonus.c															\
				$(addsuffix .c, $(addsuffix _bonus, $(addprefix srcs_bonus/parsing/, $(PARSING))))		\
				$(addsuffix .c, $(addsuffix _bonus, $(addprefix srcs_bonus/display/, $(DISPLAY))))		\
				$(addsuffix .c, $(addsuffix _bonus, $(addprefix srcs_bonus/display/, $(DISPLAY_B))))	\
				$(addsuffix .c, $(addsuffix _bonus, $(addprefix srcs_bonus/utils/, $(UTILS))))			\
				$(addsuffix .c, $(addsuffix _bonus, $(addprefix srcs_bonus/utils/, $(UTILS_B)))	)		\

OBJS		=	$(SRCS:.c=.o)

OBJS_B		=	$(SRCS_B:.c=.o)

LIBFT		=	libft/libft.a

MINILIBX	=	minilibx-linux/libmlx_Linux.a

all: $(NAME)

.c.o: $(SRCS) $(SRCS_B)
	@ $(CC) $(FLAGS) -c -o $@ $<

$(LIBFT):
	@ make -C libft --no-print-directory

$(MINILIBX):
	 @ make -C minilibx-linux --no-print-directory

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	@ $(CC) $(FLAGS) $(OBJS) $(INCLUDE) -o $(NAME)

bonus :	$(BONUS)

$(BONUS) : $(OBJS_B) $(MINILIBX) $(LIBFT)
	@ $(CC) $(FLAGS) $(OBJS_B) $(INCLUDE) -o $(NAME)
	@ touch $(BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	@ make clean -C libft 

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@ make fclean -C libft 

re:	fclean all

rec: re
	@ make clean
	clear

.PHONY: all clean fclean re rec
