/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_prepare_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/18 19:07:48 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	container(t_stack_node *a)
{
	int	container;

	container = 0;
	if (stack_size(a) >= 500)
		container = 100;
	else if (stack_size(a) >= 200)
		container = 60;
	else if (stack_size(a) >= 100)
		container = 30;
	else if (stack_size(a) < 100)
		container = stack_size(a) / 2;
	return (container);
}

void	push_a_for_b(t_stack_node **a, t_stack_node **b,
			int start, int len_a_original)
{
	int	i;
	int	container_size;
	int	middle;
	int	end;

	i = 0;
	container_size = container(*a);
	end = start + container_size;
	if (end > len_a_original - 3)
		end = len_a_original - 3;
	middle = start + (end - start) / 2;
	while (i < container_size && stack_size(*a) > 3)
	{
		if ((*a)->index >= len_a_original - 3)
			ra(a);
		else if ((*a)->index >= start && (*a)->index < end)
		{
			pb(b, a);
			if ((*b)->index < middle)
				rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	stack_up_3(t_stack_node **a, t_stack_node **b)
{
	int	len_a_original;
	int	start;

	start = 0;
	len_a_original = stack_size(*a);
	while (stack_size(*a) > 3)
	{
		push_a_for_b(a, b, start, len_a_original);
		start = stack_size(*b);
	}
	stack_3(a);
}
