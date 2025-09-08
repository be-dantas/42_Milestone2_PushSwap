/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandos_rotate_baixo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:52:30 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 19:06:12 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// o final vira o comeco e o comeco vira o segundo
void	rotate_baixo(t_stack_node **pilha)
{
	t_stack_node	*final;

	if (!*pilha || !(*pilha)->next)
		return;
	
	final = ultimo_elemento(*pilha);

	final->prev->next = NULL;

	final->prev = NULL;
	final->next = *pilha;
	(*pilha)->prev= final;
	
	*pilha = final;
}

void	rra(t_stack_node **a)
{
	rotate_baixo(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rotate_baixo(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rotate_baixo(a);
	rotate_baixo(b);
	write (1, "rrr\n", 4);
}
