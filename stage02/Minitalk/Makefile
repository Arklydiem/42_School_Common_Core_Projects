# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:56:39 by argomez           #+#    #+#              #
#    Updated: 2022/08/19 19:26:21 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Other Makefiles ##########################################################

LIBFT	= libft/libft.a

##### Mandatory ################################################################

#Commands:
AR		= ar rcs -o
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g -O0
RM		= rm -rf

#Server:
NAME_server		= server
FILES_server	=	main.c				\
					initialise_datas.c	\
					signals_handler.c	\
					
SRC_server		= $(addprefix mandatory/server_files/, $(FILES_server))
OBJ_server		= $(SRC_server:.c=.o)

#Client:
NAME_client		= client
FILES_client	= main.c
SRC_client		= $(addprefix mandatory/client_files/, $(FILES_client))
OBJ_client		= $(SRC_client:.c=.o)

##### Bonus ####################################################################

#Server:
NAME_BONUS_server 	=	.server
FILES_BONUS_server	=	main.c			\
						initialise_datas.c	\
						signals_handler.c	\
					
SRC_BONUS_server	=	$(addprefix bonus/server_files/, $(FILES_BONUS_server))
OBJ_BONUS_server	=	$(SRC_BONUS_server:.c=.o)

#Client:
NAME_BONUS_client	=	.client
FILES_BONUS_client	=	main.c
SRC_BONUS_client	=	$(addprefix bonus/client_files/, $(FILES_BONUS_client))
OBJ_BONUS_client	=	$(SRC_BONUS_client:.c=.o)

##### Rules ####################################################################

all: $(LIBFT) $(NAME_server) $(NAME_client)

bonus:	$(LIBFT) $(NAME_BONUS_server) $(NAME_BONUS_client)

$(LIBFT):
	make -C libft --no-print-directory
	
libftfclean:
	make fclean -C libft --no-print-directory

.c.o: $(SRC_server) $(SRC_client)
	$(CC) $(CFLAGS) -c -o $@ $<

clear:
	clear

$(NAME_server): $(OBJ_server)
	$(CC) $(CFLAGS) $(OBJ_server) $(LIBFT) -o $(NAME_server)
	bash display_scripts/compilation_server.sh

$(NAME_client): $(OBJ_client)
	$(CC) $(CFLAGS) $(OBJ_client) $(LIBFT) -o $(NAME_client)
	bash display_scripts/compilation_client.sh

$(NAME_BONUS_server): $(OBJ_BONUS_server)
	$(CC) $(CFLAGS) $(OBJ_BONUS_server) $(LIBFT) -o $(NAME_server)
	touch $(NAME_BONUS_server)
	bash display_scripts/compilation_server.sh

$(NAME_BONUS_client): $(OBJ_BONUS_client)
	$(CC) $(CFLAGS) $(OBJ_BONUS_client) $(LIBFT) -o $(NAME_client)
	touch $(NAME_BONUS_client)
	bash display_scripts/compilation_client.sh

clean:
	$(RM) $(OBJ_server)
	$(RM) $(OBJ_client)
	$(RM) $(OBJ_BONUS_server)
	$(RM) $(OBJ_BONUS_client)
	bash display_scripts/clean.sh

fclean: clear clean libftfclean
	$(RM) $(NAME_server)
	$(RM) $(NAME_client)
	$(RM) $(NAME_BONUS_server)
	$(RM) $(NAME_BONUS_client)
	bash display_scripts/fclean.sh

re: fclean all

.PHONY: all clean fclean re clear libftfclean
