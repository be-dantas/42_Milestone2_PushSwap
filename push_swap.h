/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:13:16 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/09 11:29:22 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // valot int MAX int MIN
# include "./LIBFT/libft.h"
#include <stdio.h>
// Guarda valores e informações úteis para manipulação da pilha.
typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

// 1_criar_pilha.c
int				int_repetidos(t_stack_node *a, int argv_atoi);
t_stack_node	*criar_pilha_a(t_stack_node *a, int argc, char **argv);

// 2_preparar_input.c
int				input_valido(char *argv_ok);
char			*fazer_join(char **argv, char *argv_ok);
char			*argv_maior_2(char **argv);
char			**tratar_input(int argc, char **argv);

// 3_elementos_pilha.c
t_stack_node	*criar_elemento_pilha(int argv_atoi);
t_stack_node	*ultimo_elemento(t_stack_node *a);
void			adicionar_int_pilha(t_stack_node *a, int argv_atoi);

// 4_free_error.c
void			free_split(char **argv_split);
void			free_all(char **argv_split, t_stack_node *a);
void			free_stack(t_stack_node *a);
void			check_error(void);

// comandos_push.c
void			push(t_stack_node **dest, t_stack_node **pilha);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// comandos_rotate_baixo.c
void			rotate_baixo(t_stack_node **pilha);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// comandos_rotate_cima.c
void			rotate_cima(t_stack_node **pilha);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// comandos_swap.c
void			swap(t_stack_node **pilha);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// 5_stack_index.c
void	index_elemento(t_stack_node **a);

#endif