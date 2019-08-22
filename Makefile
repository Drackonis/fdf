# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/08/22 18:08:11 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
main.c ft_get_next_line.c ft_getkey.c ft_setkey.c ft_settab.c ft_setwin.c\
ft_tabtopix.c ft_initmlx.c ft_drawimg.c ft_bresenham.c ft_setcolor.c\
ft_setcolor2.c ft_utils.c\
libft/ft_atoi.c libft/ft_strchr.c libft/ft_strclr.c\
libft/ft_strdel.c libft/ft_strdup.c libft/ft_strfreejoin.c\
libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strnclr.c libft/ft_strnew.c\
libft/ft_strsub.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
MLX = mlx/libmlx.a -framework OPENGL -framework AppKit
NAME = fdf
LIB = fdf.a
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(MLX)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
