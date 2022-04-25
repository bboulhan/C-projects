# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 21:37:44 by bboulhan          #+#    #+#              #
#    Updated: 2021/12/04 13:13:27 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

FILES = f2_print.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_p.c\
		ft_putstr.c pointer.c\

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all
