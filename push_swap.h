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

# include <limits.h> // int MAX int MIN
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

// 1_create_stack_a.c
void			index_element(t_stack_node **a);
int				int_repeated(t_stack_node *a, int argv_atoi);
t_stack_node	*create_stack_a(t_stack_node *a, int argc, char **argv);
int				stack_order_ok(t_stack_node *a);

// 1_prepare_input.c
int				valid_input(char *argv_ok);
char			*make_join(char **argv, char *argv_ok);
char			*argv_up_2(char **argv);
char			**treat_input(int argc, char **argv);

// 2_prepare_stack_a.c
void			stack_3(t_stack_node **a);
void			stack_2_1(t_stack_node **a);
void			stack_a_b(t_stack_node **a, t_stack_node **b);

// 2_prepare_stack_b.c
int				container(t_stack_node *a);
void			push_a_for_b(t_stack_node **a, t_stack_node **b,
					int start, int len_a_original);
void			stack_up_3(t_stack_node **a, t_stack_node **b);

// 3_push_stack_a.c
int				find_high_pos(t_stack_node *b);
void			rotate_upb_pusha(t_stack_node **a, t_stack_node **b, int i);
void			rotate_downb_pusha(t_stack_node **a,
					t_stack_node **b, int pos_maior);
void			b_for_a(t_stack_node **a, t_stack_node **b);

// elements_stack.c
t_stack_node	*create_element_stack(int argv_atoi);
t_stack_node	*last_element(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
void			add_int_stack(t_stack_node *a, int argv_atoi);

// free_error.c
void			free_split(char **argv_split);
void			free_all(char **argv_split, t_stack_node *a);
void			free_stack(t_stack_node *a);
void			check_error(void);

// commands_push.c
void			push(t_stack_node **dest, t_stack_node **stack);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// commands_rotate_down.c
void			rotate_down(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// commands_rotate_up.c
void			rotate_up(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// commands_swap.c
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

#endif