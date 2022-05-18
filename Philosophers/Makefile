# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 16:14:55 by bboulhan          #+#    #+#              #
#    Updated: 2022/04/20 16:14:58 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra

CC = cc

HEADER = philo.h \

FILES = check_and_init.c philosophers.c utils.c simulation.c \

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -f $(OBJS) $(BSRCS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all
