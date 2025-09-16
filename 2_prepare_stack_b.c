/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_prepare_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/16 19:06:08 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	containers(t_stack_node *a)
{
	int	len_a;
	int	n_containers;

	len_a = stack_size(a);
	n_containers = 0;
	while (len_a > 0)
	{
		len_a = len_a / 2;
		n_containers++;
	}
	return (n_containers);
}

int	value(t_stack_node *a, int n_containers)
{
	int	len_a;
	int	n_value;

	len_a = stack_size(a);
	n_value = len_a / n_containers;
	if (len_a % n_containers != 0)
		n_value++;
	return (n_value);
}

void	stack_b(t_stack_node **a, t_stack_node **b)
{
	int	n_containers;
	int	n_value;

	n_containers = containers(a);
	n_value = value(a, n_containers);
	if (stack_size(*a) > 3)
		stack_up_3(a, b, n_containers, n_value);
	if (stack_size(*a) == 3)
		stack_3(a);
	if (stack_size(*a) < 3)
		stack_2_1(a);
}




// void	stack_b(t_stack_node **a, t_stack_node **b)
// {
// 	int	len_a;
// 	int	temp_len_a;
// 	int	n_containers;
// 	int	n_value;
// 	int	start;
// 	int	end;
// 	int	i;

// 	len_a = stack_size(*a);
// 	temp_len_a = len_a;
// 	n_containers = 0;
// 	while (temp_len_a > 0)
// 	{
// 		temp_len_a = temp_len_a / 2;
// 		n_containers++;
// 	}
// 	n_value = len_a / n_containers;
// 	if (len_a % n_containers != 0)
// 		n_value++;

// 	start = 0;
// 	end = n_value - 1;

// 	while (stack_size(*a) > 3 && n_containers > 0)
// 	{
// 		i = 0;

// 		while (stack_size(*a) > 3 && i < n_value)
// 		{
// 			if ((*a)->index >= start && (*a)->index <= end)
// 			{
// 				pb(b, a);
// 				i++;
// 			}
// 			else
// 				ra(a);
// 		}
// 		n_containers--;
// 		start = end + 1;
// 		end = start + n_value - 1;
// 	}
// 	if (stack_size(*a) == 3)
// 		stack_up_3(a);
// 	if (stack_size(*a) < 3)
// 		stack_up_2_1(a);
// }
