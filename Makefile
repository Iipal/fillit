# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 13:24:35 by tmaluh            #+#    #+#              #
#    Updated: 2018/11/12 11:31:20 by kpshenyc         ###   ########.fr        #
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
		srcs/ft_solve.c \
		srcs/ft_free.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
LGREEN=\033[92m
RED=\033[31m
ORANGE=\033[33m
YELLOW=\033[93m
PURPLE=\033[34m
L=\033[36m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo "$LFILLIT:$(GREEN)\tCompiling file:$(YELLOW)" $< "$(WHITE)to$(PURPLE)" $@ "$(WHITE)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@echo "\t\t$LFILLIT$(WHITE)"
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$LFILLIT:$(GREEN)\tCompiling FILLIT executable...$(WHITE)"
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$LFILLIT:$(LGREEN)\tCompiled & ./fillit ready for use.$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@echo "$LFILLIT:$(ORANGE)\tRemoved: *.o files...$(WHITE)"
	@$(LMAKE) clean

fclean: clean
	@$(DEL) -rf $(NAME)
	@echo "$LFILLIT:$(RED)\tRemoved: fdf...$(WHITE)"
	@$(LMAKE) fclean

re: fclean all

.PHONY: all clean fclean clean re
