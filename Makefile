# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 16:27:42 by hadufer           #+#    #+#              #
#    Updated: 2021/09/05 15:54:40 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
CLIENT	= client
SERVER	= server

SRCS	=	client.c\
			server.c

OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -I./Libft -o $@ $<

all: $(NAME)

$(NAME):	libft ${OBJS} $(CLIENT) $(SERVER)

$(CLIENT): libft
	$(CC) $(CLIENT).c -L./Libft -l:libft.a -I./Libft -o $(CLIENT)

$(SERVER): libft
	$(CC) $(SERVER).c -L./Libft -l:libft.a -I./Libft -o $(SERVER)

libft:
	$(MAKE) -C ./Libft

clean:
		$(MAKE) -C ./Libft $@
		${RM} ${OBJS}

fclean:	clean
		$(MAKE) -C ./Libft $@
		${RM} ${CLIENT}
		${RM} ${SERVER}

re: fclean all

.PHONY:	all clean fclean re libft
