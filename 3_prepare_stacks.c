/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_prepare_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/15 17:50:46 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_up_3(t_stack_node **a)
{
	if (stack_size(*a) == 1)
		return ;
	else if (stack_size(*a) == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (stack_size(*a) == 3)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		if (((*a)->index > (*a)->next->index) 
			&& ((*a)->index > (*a)->next->next->index))
			ra(a);
		if ((*a)->next->index > (*a)->next->next->index)
			rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}

void	stack_b(t_stack_node **a, t_stack_node **b)
{
	int	len_original;
	int	middle_stack;

	len_original = stack_size(*a);
	middle_stack = (len_original / 2) - 1;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index > len_original - 4)
			ra(a);
		else
		{
			pb(b, a);
			if ((*b)->index < middle_stack)
				rb(b);
		}
	}
	if (len_original <= 3)
		stack_up_3(a);
}

// void	stack_b(t_stack_node **a, t_stack_node **b)
// {
// 	int	len_original;
// 	int	middle_stack;

// 	len_original = stack_size(*a);
// 	middle_stack = (len_original / 2) - 1;
// 	if (len_original <= 3)
// 	{
// 		stack_up_3(a);
// 		return ;
// 	}
// 	while (stack_size(*a) > 3)
// 	{
// 		if ((*a)->index > len_original - 4)
// 			ra(a);
// 		else
// 		{
// 			pb(b, a);
// 			if ((*b)->index > middle_stack)
// 				rb(b);
// 		}
// 	}
// }
