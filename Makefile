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

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/main.c\
		srcs/ft_cut_figure.c \
		srcs/ft_gnl.c \
		srcs/ft_map.c \
		srcs/ft_readnvalid.c \
		srcs/ft_readnvalid_additional.c \
		srcs/ft_solve.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

LMAKE = make -C libft

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(DEL) $(OBJ)
	$(LMAKE) clean

fclean: clean
	$(DEL) -rf $(NAME)
	$(LMAKE) fclean

re: fclean all

.PHONY: all clean fclean clean re