/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_prepare_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/18 19:00:47 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_a_b(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) < 3)
		stack_2_1(a);
	else if (stack_size(*a) == 3)
		stack_3(a);
	else
		stack_up_3(a, b);
}
