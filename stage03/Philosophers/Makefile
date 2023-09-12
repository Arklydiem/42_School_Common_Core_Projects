# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:56:39 by argomez           #+#    #+#              #
#    Updated: 2022/09/14 15:47:38 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Other Makefiles ##########################################################

##### Compilation ##############################################################

#Commands:
AR				= ar rcs -o
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -O0 -pthread
RM				= rm -rf

# Mandatory:
NAME			= philo
FILES_MANDATORY	= main.c					

# Bonus:
NAME_BONUS		= .philo
FILES_BONUS		=

# Utils:
FILES_UTILS		=	better_usleep.c		\
					better_mssleep.c	\
					get_time.c			\
					ft_atoi.c			\
					print_messages.c	\
					check_args.c		\
					args_conformity.c	\
					args_length.c		\

# Routine :
FILES_ROUTINE	=	check_deaths.c		\
					check_eats.c		\
					lives.c				\
					eating.c			\
					sleeping.c			\
					thinking.c			\

# SRCS:
FILES_SRCS		=	initialise_all.c	\
					create_threads.c	\

SRC				=	$(addprefix srcs/mandatory/, $(FILES_MANDATORY))	\
					$(addprefix srcs/routine/, $(FILES_ROUTINE))		\
					$(addprefix srcs/utils/, $(FILES_UTILS))			\
					$(addprefix srcs/, $(FILES_SRCS))					\

SRC_BONUS		=	$(addprefix srcs/bonus/, $(FILES_BONUS))	\
					$(addprefix srcs/, $(FILES_SRCS))

OBJ				= $(SRC:.c=.o);
OBJ_BONUS		= $(SRC_BONUS:.c=.o)

##### Rules ####################################################################

all: $(NAME)

.c.o: $(SRC)
	@ echo -n "\e[94m"
	$(CC) $(CFLAGS) -c -o $@ $<
	@ echo -n "\e[39m"

clear:
	clear

$(NAME): $(OBJ)
	@ echo "\e[34m"
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)
	@ echo "\e[39m"
	@ bash display_scripts/compilation.sh

$(NAME_BONUS): $(OBJ)
	@ echo "\e[34m"
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)
	@ echo "\e[39m"
	@ bash display_scripts/compilation.sh

clean:
	@ echo -n "\e[38;5;208m"
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	@ echo "\e[39m"
	@ bash display_scripts/clean.sh

fclean: clear clean
	@ echo -n "\e[38;5;208m"
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@ echo "\e[39m"
	@ bash display_scripts/fclean.sh

re: fclean all

rec: fclean all
	@ make clean --no-print-directory

.PHONY: all clean fclean re clear rec
