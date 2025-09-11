/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandos_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:20:28 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/09 14:40:35 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **stack)
{
	t_stack_node	*item;

	if (*stack == NULL)
		return ;
	item = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = item;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
	}
	else
	{
		item->next = *dest;
		item->prev = NULL;
		(*dest)->prev = item;
		*dest = item;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write (1, "pb\n", 3);
}
