# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 14:06:22 by bboulhan          #+#    #+#              #
#    Updated: 2022/06/25 16:58:10 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

CC = cc

HEADER = minishell.h \

FILES = minishell.c ./utils/utils.c ./utils/ft_split.c ./utils/utils_2.c ./utils/ft_strtrim.c ./utils/red_utils.c \
		./Parser/lexer.c ./Parser/parcer.c ./Parser/set_args_utils.c ./Parser/set_args.c \
		./Parser/lexer_utils.c ./Parser/redirection_parcer.c ./Parser/red_parcer_utils.c \
		./Execution/export/export.c ./Execution/echo/echo.c ./Execution/cd/cd.c ./Execution/pwd/pwd.c \
		./Execution/env/env.c ./Execution/exit/exit.c\

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)
	clear

clean : 
	rm -f $(OBJS)
	clear

fclean : clean
	rm -f $(NAME)
	clear

re : fclean all

.PHONY : re fclean clean all
