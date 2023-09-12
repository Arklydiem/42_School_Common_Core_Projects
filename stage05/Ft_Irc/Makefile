# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 20:04:36 by vnadal            #+#    #+#              #
#    Updated: 2023/01/25 16:36:42 by vnadal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		=  --no-print-directory
NAME			=	ircserv
CC				=	c++
FLAGS			=	-Wall -Werror -Wextra -std=c++98 -g
RM				=	rm -f

SRCS			=	./main.cpp				\
					./Server/Server.cpp		\
					./Server/nick.cpp		\
					./Server/pass.cpp		\
					./Server/user.cpp		\
					./Server/utils.cpp		\
					./Server/join.cpp		\
					./Server/invite.cpp		\
					./Server/mode.cpp		\
					./Server/kick.cpp		\
					./Server/topic.cpp		\
					./Server/botCmd.cpp		\
					./Server/part.cpp		\
					./Server/privMsg.cpp	\
					./Client/Client.cpp		\
					./Channel/Channel.cpp	\
					./Command/Command.cpp	\

BONUS			=	./Bot/main.cpp			\
					./Bot/Bot.cpp			\

OBJ				=	$(SRCS:.cpp=.o)

OBJ_BONUS		=	$(BONUS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $< -o $@ $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_BONUS)

fclean:	clean
	@ $(RM) $(NAME)
	@ $(RM) bot

re:	fclean all

rec: fclean clear $(NAME)
	@ make clean --no-print-directory

clear:
	clear

bonus: $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o bot

.PHONY: all clean fclean re rec clear bonus
