/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_prepare_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/17 15:23:54 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_container_to_b(t_stack_node **a, t_stack_node **b,
			int start, int end)
{
	int	i;
	int	n_value;
	int	middle;

	i = 0;
	n_value = end - start + 1;
	middle = (start + end) / 2;
	while (stack_size(*a) > 3 && i < n_value)
	{
		if ((*a)->index >= start && (*a)->index <= end)
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

void	push_last_to_b(t_stack_node **a, t_stack_node **b, int len_a)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < len_a - 3)
			pb(b, a);
		else
			ra(a);
	}
}

void	stack_up_3(t_stack_node **a, t_stack_node **b,
			int n_containers, int n_value)
{
	int	container_idx;
	int	len_a_original;
	int	start;
	int	end;

	container_idx = 0;
	len_a_original = stack_size(*a);
	while (stack_size(*a) > 3 && n_containers > 1)
	{
		start = container_idx * n_value;
		end = start + n_value - 1;
		if (end > len_a_original - 4)
			end = len_a_original - 4;
		push_container_to_b(a, b, start, end);
		container_idx++;
		n_containers--;
	}
	push_last_to_b(a, b, len_a_original);
	stack_3(a);
}

void	stack_3(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

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
