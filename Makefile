# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 09:30:58 by bedantas          #+#    #+#              #
#    Updated: 2025/09/05 15:20:42 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c			\
		criando_pilha_a.c	\
		free_error.c		\
		preparar_input.c

OBJS = $(SRCS:.c=.o)

RMAKE = make re

all: $(NAME)

$(NAME): $(OBJS)
	cd ./LIBFT && $(RMAKE)
	cp ./LIBFT/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd ./LIBFT && make clean

fclean: clean
	rm -f $(NAME)
	cd ./LIBFT && make fclean

re: fclean all

.PHONY: all clean fclean re
