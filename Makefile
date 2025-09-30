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
		create_stack_a.c		\
		prepare_input.c			\
		prepare_stack_a.c		\
		prepare_stack_b.c		\
		push_stack_a.c			\
		elements_stack.c		\
		free_error.c			\
		commands_push.c			\
		commands_rotate_down.c	\
		commands_rotate_up.c	\
		commands_swap.c

OBJS = $(SRCS:.c=.o)

RMAKE = make re

all: $(NAME)

$(NAME): $(OBJS)
	cd ./libft && $(RMAKE)
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	cc push_swap.c $(NAME) -o push_swap
	rm -f push_swap.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re
