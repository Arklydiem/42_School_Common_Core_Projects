# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 09:21:09 by argomez           #+#    #+#              #
#    Updated: 2023/01/13 09:21:09 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *** # Compilation # ******************************************************** #

MAKEFLAGS	=	--no-print-directory
NAME		=	HarlFilter
CC			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -g
RM			=	rm -rf

# *** # Files # ************************************************************** #

SRCS		=	main.cpp	\
				Harl.cpp

OBJS		=	$(SRCS:.cpp=.o)

# *** # Compilation # ******************************************************** #

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ 

all: $(NAME)

clear:
	clear

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clear clean
	$(RM) $(NAME)

re: fclean all 

rec: fclean $(NAME)
	@ make clean --no-print-directory
	clear

.PHONY: all clean fclean re clear rec
