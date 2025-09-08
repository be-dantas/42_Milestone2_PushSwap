/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandos_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:21:45 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 17:31:50 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **pilha)
{
	t_stack_node	*item_1;
	t_stack_node	*item_2;

	if (*pilha == NULL || (*pilha)->next == NULL)
		return ;
	item_1 = *pilha;
	item_2 = (*pilha)->next;
	item_1->prev = item_2;
	item_1->next = item_2->next;
	if (item_2->next)
		item_2->next->prev = item_1;
	item_2->prev = NULL;
	item_2->next = item_1;
	*pilha = item_2;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
