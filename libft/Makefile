# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 11:27:37 by tmaluh            #+#    #+#              #
#    Updated: 2018/11/19 15:48:22 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -march=native
LC = ar rcs

CFLAGS = -Wall -Wextra -Werror -std=c99

WHITE=\033[0m
GREEN=\033[32m
LGREEN=\033[92m
RED=\033[31m
ORANGE=\033[33m
YELLOW=\033[93m
PURPLE=\033[34m
L=\033[36m

DEL = rm -rf

LIBSRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		 ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		 ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		 ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_toupper.c ft_tolower.c \
		 ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		 ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		 ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		 ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		 ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		 ft_lstmap.c \
		 ft_pow.c ft_strndup.c ft_sqrt.c ft_strlcpy.c ft_isupper.c ft_islower.c \
		 ft_isnumber.c ft_isblank.c ft_count_if.c ft_strrchri.c ft_strchri.c 

LIBOBJ = $(LIBSRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBOBJ)
	@echo "$LLIBFT:$(GREEN)\tCompiling LIBFT...$(WHITE)"
	@$(LC) $(NAME) $(LIBOBJ)
	@echo "$LLIBFT:$(LGREEN)\tCompiled & libft.a ready for use.$(WHITE)"

$(LIBOBJ): %.o: %.c
	@echo "$LLIBFT:$(GREEN)\tCompiling file:$(YELLOW)" $< "$(WHITE)to$(PURPLE)" $@ "$(WHITE)"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@$(DEL) $(LIBOBJ)
	@echo "$LLIBFT:$(ORANGE)\tRemoved: *.o files.$(WHITE)"

fclean: clean
	@$(DEL) $(NAME)
	@echo "$LLIBFT:$(RED)\tRemoved: libft.a.$(WHITE)"

re: fclean all

.PHONY: re fclean clean all test
