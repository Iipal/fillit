# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 13:24:35 by tmaluh            #+#    #+#              #
#    Updated: 2018/11/03 13:24:36 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P = fillit

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -o
LFLAGS = -L libft/ -lft
LMAKE = make -C libft/

SRCS = ./srcs/

DEL = rm -rf

all: lft $P

lft:
	$(LMAKE) re

$P:
	$(CC) $(SRCS)main.c $(SRCS)ft_readnvalid.c $(SRCS)ft_gnl.c \
	$(SRCS)ft_readnvalid_additional.c $(SRCS)ft_cut_figure.c \
	$(SRCS)ft_free.c \
	$(LFLAGS) $(CFLAGS) ./$P

clean:
	$(LMAKE) clean

fclean: clean
	$(LMAKE) fclean
	$(DEL) ./$P

re: fclean all

.PHONY: all clean fclean re $P
