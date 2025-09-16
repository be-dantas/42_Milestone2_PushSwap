/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_passar_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:29:24 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/16 11:49:12 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	achar_maior_pos(t_stack_node *b)
{
	int	pos_maior;

	if (!b)
		return (-1);
	pos_maior = b->index;
	while (b)
	{
		if (b->index > pos_maior)
			pos_maior = b->index;
		b = b->next;
	}
	return (pos_maior);
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


void	passar_b_para_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*andar_b;
	int 			i;
	int				len_b;
	int				middle_stack;
	int 			pos_maior;

	if (!a || !b || !*b)
		return ;
	while (*b)
	{
		andar_b = *b;
		i = 0;
		len_b = stack_size(*b);
		middle_stack = (len_b / 2); // -1
		pos_maior = achar_maior_pos(*b);
		while (andar_b->index != pos_maior)
		{
			andar_b = andar_b->next;
			i++;
		}
		if (i <= middle_stack)
			rotate_upb_pusha(a, b, i);
		else if (i > middle_stack)
			rotate_downb_pusha(a, b, len_b - i);
	}
}
