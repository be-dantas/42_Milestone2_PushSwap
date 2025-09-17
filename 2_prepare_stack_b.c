/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_prepare_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/17 16:41:37 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	containers(t_stack_node *a)
{
	int	len_a;
	int	n_containers;

	len_a = stack_size(a) - 3;
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

	len_a = stack_size(a) - 3;
	n_value = len_a / n_containers;
	if (len_a % n_containers != 0)
		n_value++;
	return (n_value);
}

void	stack_b(t_stack_node **a, t_stack_node **b)
{
	int	n_containers;
	int	n_value;

	n_containers = containers(*a);
	n_value = value(*a, n_containers);
	if (stack_size(*a) < 3)
		stack_2_1(a);
	else if (stack_size(*a) == 3)
		stack_3(a);
	else
		stack_up_3(a, b, n_containers, n_value);
}
