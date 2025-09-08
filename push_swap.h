/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:13:16 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 18:50:35 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // valot int MAX int MIN
# include "./LIBFT/libft.h"

// Guarda valores e informações úteis para manipulação da pilha.
typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

// crian_pilha_a.c
t_stack_node	*criar_elemento_pilha(int argv_atoi);
t_stack_node	*ultimo_elemento(t_stack_node *a);
void			adicionar_int_pilha(t_stack_node *a, int argv_atoi);

// free_error.c
void			free_split(char **argv_split);
void			free_all(char **argv_split, t_stack_node *a);
void			free_stack(t_stack_node *a);
void			check_error(void);

// preparando_input.c
char			*argv_maior_2(char **argv);
int				int_repetidos(t_stack_node *a, int argv_atoi);
int				input_valido(char *argv_ok);
char			**tratar_input(int argc, char **argv);
t_stack_node	*criar_pilha_a(t_stack_node *a, int argc, char **argv);

// comandos_push.c
void			push(t_stack_node **dest, t_stack_node **pilha);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// comandos_swap.c
void			swap(t_stack_node **pilha);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// comandos_rotate_baixo.c
void			rotate_baixo(t_stack_node **pilha);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif