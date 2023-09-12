# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:56:39 by argomez           #+#    #+#              #
#    Updated: 2022/07/16 12:55:59 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define display_compilation 
	@ echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*"
	@ echo "\e[34m     *                              \e[94m*"
	@ echo "\e[94m     *     \e[96mCompilation Complete\e[0m     \e[34m*"
	@ echo "\e[34m     *                              \e[94m*"
	@ echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[0m"
endef

define display_clean 
	@ echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*"
	@ echo "\e[34m     *                              \e[94m*"
	@ echo "\e[94m     *        \e[96mClean Complete        \e[34m*"
	@ echo "\e[34m     *                              \e[94m*"
	@ echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[0m"
endef


NAME		=	push_swap

LIBFT       =   libft/libft.a

MANDATORY	=	main.c										\

COMMON		=	args_conformity.c							\
				find_size.c									\
				ft_error.c									\
				init_tabs.c									\
				ft_frees.c									\
				fill_tab.c									\
				check_formating.c							\
				display_tabs.c								\
				sort_tabs.c									\
				add_index.c									\

OPERATIONS	=	swap_a.c									\
				swap_b.c									\
				swap_a_b.c									\
				push_a.c									\
				push_b.c									\
				rotate_a.c									\
				rotate_b.c									\
				rotate_a_b.c								\
				reverse_rotate_a.c							\
				reverse_rotate_b.c							\
				reverse_rotate_a_b.c						\

ALGORITHMS	=	sort_sujet.c								\
				sort_three.c								\
				sort_four.c									\
				sort_five.c									\
				sort_others.c								\

AR			=	ar rcs -o
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -f

SRC			=	$(addprefix mandatory/, $(MANDATORY))		\
				$(addprefix operations/, $(OPERATIONS))		\
				$(addprefix algorithms/, $(ALGORITHMS))		\
				$(COMMON)									\

OBJ			=	$(SRC:.c=.o)

.c.o: $(SRC)
	@ $(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(LIBFT):
	@ make -C libft --no-print-directory

$(NAME):	$(LIBFT)	$(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	$(display_compilation)

clean:
	@ $(RM) $(OBJ)
	$(display_clean)

cleanLibft:
	@ make fclean -C libft --no-print-directory

fclean:	clear clean cleanLibft
	@ $(RM) $(NAME)

clear:
	@ clear

re:	fclean all

.PHONY: all clean cleanLibft fclean clear re
