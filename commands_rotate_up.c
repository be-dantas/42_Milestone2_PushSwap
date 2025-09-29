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

void	rotate_up(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*end;

	if (!*stack || !(*stack)->next)
		return ;
	top = *stack;
	end = last_element(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	top->prev = end;
	top->next = NULL;
	end->next = top;
}

void	ra(t_stack_node **a)
{
	rotate_up(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate_up(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_up(a);
	rotate_up(b);
	write (1, "rr\n", 3);
}
