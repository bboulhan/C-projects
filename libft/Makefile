# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 17:11:04 by bboulhan          #+#    #+#              #
#    Updated: 2021/11/30 21:59:25 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

FILES = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
		ft_strlcat.c ft_atoi.c ft_substr.c ft_putchar_fd.c\
		ft_strlcpy.c ft_tolower.c ft_bzero.c  ft_strlen.c ft_putstr_fd.c\
		ft_toupper.c ft_calloc.c ft_memchr.c ft_isalnum.c ft_striteri.c ft_putendl_fd.c\
		ft_memcmp.c ft_split.c ft_strncmp.c ft_putnbr_fd.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
		ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_itoa.c ft_strmapi.c\

BFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c

OBJS = $(FILES:.c=.o)

BOBJS = $(BFILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus : $(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all bonus
