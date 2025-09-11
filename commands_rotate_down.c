/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandos_rotate_baixo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:52:30 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/09 14:41:08 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// o final vira o comeco, e o final vira o penultimo
void	rotate_down(t_stack_node **stack)
{
	t_stack_node	*end;

	if (!*stack || !(*stack)->next)
		return ;
	end = last_element(*stack);
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *stack;
	(*stack)->prev = end;
	*stack = end;
}

void	rra(t_stack_node **a)
{
	rotate_down(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rotate_down(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rotate_down(a);
	rotate_down(b);
	write (1, "rrr\n", 4);
}
