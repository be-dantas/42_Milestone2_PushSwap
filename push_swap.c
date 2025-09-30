/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:11:02 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/09 14:41:39 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = create_stack_a(a, argc, argv);
	if (!a)
		return (0);
	if (stack_order_ok(a))
	{
		free_stack(a);
		return (0);
	}
	stack_a_b(&a, &b);
	b_for_a(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
