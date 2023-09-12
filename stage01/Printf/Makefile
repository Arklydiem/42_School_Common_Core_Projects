# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 13:37:47 by argomez           #+#    #+#              #
#    Updated: 2022/04/22 13:23:37 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c			\
			ft_print_char.c		\
			ft_print_str.c		\
			ft_print_nbr.c		\
			ft_print_decimal.c	\
			ft_print_hexa.c		\
			ft_print_ptr.c		\
			ft_print_unsigned.c	\

OBJ		=	$(SRC:.c=.o)

cc		=	gcc

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs -o $(NAME) *.o

clean	:
	$(RM) *.o

fclean	:	clean
	$(RM) *.a

re		:	fclean all

.PHONY	:	all clean fclean re
