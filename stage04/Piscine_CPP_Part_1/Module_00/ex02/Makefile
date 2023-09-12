# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:03:21 by argomez           #+#    #+#              #
#    Updated: 2023/02/27 16:03:37 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *** # Compilation # ******************************************************** #

NAME		=    exec
CC			=    c++
FLAGS		=    -Wall -Werror -Wextra -std=c++98 -ggdb3
RM			=    rm -f

# *** # Files # ************************************************************** #

OBJ			=    $(SRCS:.cpp=.o)

SRCS		=	main.cpp	\
				Account.cpp	\


# *** # Compilation # ******************************************************** #

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clear:
	clear

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clear clean
	$(RM) $(NAME)

re: fclean all 

rec: fclean $(NAME)
	@ make clean --no-print-directory
	clear

.PHONY: all clean fclean re clear rec
