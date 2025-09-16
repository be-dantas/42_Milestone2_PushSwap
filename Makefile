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
		1_create_stack_a.c		\
		1_prepare_input.c		\
		2_prepare_stack_a.c		\
		2_prepare_stack_b.c		\		
		3_push_stack_a.c		\
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
