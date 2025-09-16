/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_prepare_stacks copy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/16 14:35:08 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_up_3(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(*a) == 1)
		return ;
	if (stack_size(*a) == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		return ;
	}
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	stack_b(t_stack_node **a, t_stack_node **b)
{
	int	len_original;
	int	middle_stack;

	len_original = stack_size(*a);
	middle_stack = (len_original / 2);
	while (stack_size(*a) > 3)
	{
		if ((*a)->index >= len_original - 3)
			ra(a);
		else
		{
			pb(b, a);
			if ((*b)->index < middle_stack)
				rb(b);
		}
	}
	stack_up_3(a);
}
