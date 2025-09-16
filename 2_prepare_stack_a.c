/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_prepare_stacks_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/16 18:38:44 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_up_3(t_stack_node **a, t_stack_node **b, int n_containers, int n_value)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = n_value - 1;
	while (stack_size(*a) > 3 && n_containers > 0)
	{
		i = 0;
		while (stack_size(*a) > 3 && i < n_value)
		{
			if ((*a)->index >= start && (*a)->index <= end)
			{
				pb(b, a);
				i++;
			}
			else
				ra(a);
		}
		n_containers--;
		start = end + 1;
		end = start + n_value - 1;
	}
}

void	stack_3(t_stack_node **a)
{
	int first;
	int second;
	int third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third)
		rra(a);
}

void	stack_2_1(t_stack_node **a)
{
	if (stack_size(*a) == 1)
		return ;
	if (stack_size(*a) == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}

