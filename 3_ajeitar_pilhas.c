/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ajeitar_pilhas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:32 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/11 16:21:29 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pilha_até_3(t_stack_node **a)
{
	if (tamanho_pilha(*a) == 1)
		return ;
	else if (tamanho_pilha(*a) == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (tamanho_pilha(*a) == 3)
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

void	pilha_b(t_stack_node **a, t_stack_node **b)
{
	int	len_orinal;
	int	meio_pilha;

	len_orinal = tamanho_pilha(*a);
	meio_pilha = (len_orinal / 2) - 1;
	if (len_orinal <= 3)
	{
		pilha_até_3(a);
		return ;
	}
	while (tamanho_pilha(*a) > 3)
	{
		if ((*a)->index > len_orinal - 4)
			ra(a);
		else
		{
			pb(b, a);
			if ((*b)->index > meio_pilha)
				rb(b);
		}
	}
}
