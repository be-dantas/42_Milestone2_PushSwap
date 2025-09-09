/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandos_rotate_cima.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:02:10 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/09 14:40:55 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// o começo vira o final, e o comeco vira o segundo
void	rotate_cima(t_stack_node **pilha)
{
	t_stack_node	*topo;
	t_stack_node	*final;

	if (!*pilha || !(*pilha)->next)
		return ;
	topo = *pilha;
	final = ultimo_elemento(*pilha);
	*pilha = (*pilha)->next;
	(*pilha)->prev = NULL;
	topo->prev = final;
	topo->next = NULL;
	final->next = topo;
}

void	ra(t_stack_node **a)
{
	rotate_cima(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate_cima(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_cima(a);
	rotate_cima(b);
	write (1, "rr\n", 3);
}
