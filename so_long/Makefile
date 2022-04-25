# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 20:54:40 by bboulhan          #+#    #+#              #
#    Updated: 2022/04/08 20:54:56 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

CC = cc

HEADER = ./mandatory/so_long.h \

HEADER_B = ./bonus/so_long_bonus.h \

FILES = ./mandatory/so_long.c ./mandatory/utils.c ./mandatory/get_next_line.c \
		./mandatory/get_next_line_utils.c ./mandatory/utils_2.c ./mandatory/check_map.c \
		./mandatory/check_map_utils.c ./mandatory/movement.c ./mandatory/draw.c \
		./mandatory/movement_2.c \

SRCS =  ./bonus/so_long_bonus.c ./mandatory/get_next_line.c ./bonus/movement_bonus_2.c ./bonus/ft_itoa.c \
		./mandatory/get_next_line_utils.c ./mandatory/utils_2.c ./bonus/check_map_bonus.c \
		./bonus/check_map_utils_bonus.c ./bonus/movement_bonus.c ./bonus/draw_bonus.c ./mandatory/utils.c \

BSRCS = $(SRCS:%.c=%.o)

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(BSRCS) $(HEADER_B)
	$(CC) $(CFLAGS) $(BSRCS) -lmlx -framework OpenGL -framework AppKit -o so_long_bonus

clean : 
	rm -f $(OBJS) $(BSRCS)

fclean : clean
	rm -f $(NAME) so_long_bonus

re : fclean all

.PHONY : re fclean clean all