# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 09:28:12 by mmarks            #+#    #+#              #
#    Updated: 2023/01/24 10:51:49 by vnadal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar -rcs

SRCS	=	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line_utils.c \
			get_next_line.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf.c \
			ft_join_free.c	\
			ft_realloc_tab_str.c\

OBJS	=	${SRCS:.c=.o}
NAME	=	libft.a
RM	=		rm -f

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			@${AR} ${NAME} $^

clean:
			@${RM} ${OBJS} ${O_BONUS}

fclean:		clean
			@${RM} ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re
