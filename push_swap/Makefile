# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 14:34:20 by bboulhan          #+#    #+#              #
#    Updated: 2022/03/19 14:37:25 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

BONUS = checker

CFLAGS = -Wall -Werror -Wextra

CC = cc

FILES = ./mandatory/algo.c ./mandatory/algo_utils2.c ./mandatory/instructions_2.c \
		./mandatory/utils.c ./mandatory/algo_utils.c ./mandatory/instructions.c \
		./mandatory/push_swap.c ./mandatory/stock.c ./mandatory/utils_2.c ./mandatory/arguments.c \
		./mandatory/check.c ./mandatory/clean_stack.c ./mandatory/ft_split.c\
		
BNFLS = ./bonus/instructions_bonus_2.c ./mandatory/utils.c ./bonus/clean_bonus.c \
		./bonus/instructions_bonus.c ./bonus/checker_bonus.c ./mandatory/stock.c \
		./mandatory/check.c ./bonus/get_next_line_utils.c ./mandatory/arguments.c \
		./bonus/get_next_line.c ./bonus/ft_strncmp.c ./mandatory/ft_split.c \
		

OBJS = $(FILES:%.c=%.o)

BOBJS = $(BNFLS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(BOBJS)
	@$(CC) $(CFLAGS) $(BOBJS) -o $(BONUS)

clean : 
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : re fclean clean all
