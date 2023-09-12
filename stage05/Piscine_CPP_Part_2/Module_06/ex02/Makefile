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
NAME		=	a.out
CC			=	c++
FLAGS		=	-Iincludes -Wall -Werror -Wextra -std=c++98 -g
RM			=	rm -rf

# *** # Files # ************************************************************** #

SRCS_FILES	=	main	\
				Base	\
				A		\
				B		\
				C		\

SRCS_PATH	=	$(addsuffix .cpp, $(addprefix srcs/, $(SRCS_FILES)))

OBJS		=	$(SRCS_PATH:.cpp=.o)

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

test:
	clear
	./a.out -
	@echo
	./a.out .
	@echo
	./a.out 0
	@echo
	./a.out +
	@echo
	./a.out c
	@echo
	./a.out 92
	@echo
	./a.out +92
	@echo
	./a.out -92
	@echo
	./a.out 4
	@echo
	./a.out 681187
	@echo
	./a.out "+inf     "
	@echo
	./a.out 684684168416
	@echo
	./a.out 684684168416.5f
	@echo
	./a.out 198.f
	@echo
	./a.out .98741f
	@echo
	./a.out -.98741f
	@echo
	./a.out 5.5
	@echo
	./a.out 5.
	@echo
	./a.out -5.
	@echo
	./a.out .9
	@echo
	./a.out 2147483648
	@echo
	./a.out 2147483647
	@echo
	./a.out -2147483649
	@echo
	./a.out -2147483648
	@echo
	./a.out nan
	@echo
	./a.out inf
	@echo
	./a.out -inf
	@echo
	./a.out +inf
	@echo
	./a.out inff
	@echo
	./a.out +inff
	@echo
	./a.out -inff
	@echo
	./a.out 999999999999999999999999999999999999999999.5
	@echo
	./a.out glkjwbgwlkj
	@echo
	./a.out ""
	@echo

.PHONY: all clean fclean re clear rec test
