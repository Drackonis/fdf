# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/01/11 13:35:17 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
ft_fdf.c fdf.c fdf.c\
fdf.c fdf.c\
fdf.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
NAME = fdf
LIB = fdf.a
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
