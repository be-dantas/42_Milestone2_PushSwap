# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 09:30:58 by bedantas          #+#    #+#              #
#    Updated: 2025/09/09 11:30:05 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c				\
		1_criar_pilha.c			\
		2_preparar_input.c		\
		3_ajeitar_pilhas.c		\
		elementos_pilha.c		\
		free_error.c			\
		comandos_push.c			\
		comandos_rotate_baixo.c	\
		comandos_rotate_cima.c	\
		comandos_swap.c

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
