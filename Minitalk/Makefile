# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 13:26:47 by bboulhan          #+#    #+#              #
#    Updated: 2022/01/08 18:00:29 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

CLBONUS = client_bonus.c convert_send_bonus.c client_utils_bonus.c \

SEBONUS = server_bonus.c server_utils_bonus.c \

CLIENTM = client.c convert_send.c client_outils.c \

SERVER = server.c server_outils.c \

COBJSBS = $(CLBONUS:%.c=%.o)

SOBJSBS = $(SEBONUS:%.c=%.o)

CLSRCS = $(CLIENTM:%.c=%.o)

SESRCS = $(SERVER:%.c=%.o)

all : client server

bonus : client_bonus server_bonus

client : $(CLSRCS)
	@$(CC) $(CFLAGS) $(CLSRCS) -o client

server : $(SESRCS)
	@$(CC) $(CFLAGS) $(SESRCS) -o server

client_bonus: $(COBJSBS)
	@$(CC) $(CFLAGS) $(COBJSBS) -o client_bonus

server_bonus : $(SOBJSBS)
	@$(CC) $(CFLAGS) $(SOBJSBS) -o server_bonus

clean :
	rm -f $(COBJSBS) $(SOBJSBS) $(CLSRCS) $(SESRCS)

fclean : clean
	rm -f client server client_bonus server_bonus

re : fclean all

.PHONY : re fclean clean all
