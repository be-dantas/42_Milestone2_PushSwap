/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_push_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:29:24 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/17 14:35:18 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_high_pos(t_stack_node *b)
{
	int	pos_high;

	if (!b)
		return (-1);
	pos_high = b->index;
	while (b)
	{
		if (b->index > pos_high)
			pos_high = b->index;
		b = b->next;
	}
	return (pos_high);
}

void	rotate_upb_pusha(t_stack_node **a, t_stack_node **b, int i)
{
	while (i > 0)
	{
		rb(b);
		i--;
	}
	pa(a, b);
}

void	rotate_downb_pusha(t_stack_node **a, t_stack_node **b, int i)
{
	while (i > 0)
	{
		rrb(b);
		i--;
	}
	pa(a, b);
}

void	b_for_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_b;
	int				i;
	int				len_b;
	int				middle_stack;
	int				pos_high;

	if (!a || !b || !*b)
		return ;
	while (*b)
	{
		temp_b = *b;
		i = 0;
		len_b = stack_size(*b);
		middle_stack = (len_b / 2);
		pos_high = find_high_pos(*b);
		while (temp_b->index != pos_high)
		{
			temp_b = temp_b->next;
			i++;
		}
		if (i <= middle_stack)
			rotate_upb_pusha(a, b, i);
		else if (i > middle_stack)
			rotate_downb_pusha(a, b, len_b - i);
	}
}
