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

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o
LFLAGS = -L libft/ -lft
LMAKE = make -C libft/

SRCS = ./srcs/

DEL = rm -rf

all: lft $P

lft:
	$(LMAKE) re

$P:
	$(CC) $(SRCS)main.c $(SRCS)ft_errno_validfile.c $(SRCS)ft_gnl.c \
	$(LFLAGS) $(CFLAGS) ./$P

clean:
	$(LMAKE) clean

fclean: clean
	$(LMAKE) fclean
	$(DEL) ./$P

re: fclean all

.PHONY: all clean fclean re $P