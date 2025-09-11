/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_elementos_pilha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:36:07 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/11 12:36:07 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_element_stack(int argv_atoi)
{
	t_stack_node	*item;

	item = malloc(sizeof(t_stack_node));
	if (!item)
		return (NULL);
	item->value = argv_atoi;
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

t_stack_node	*last_element(t_stack_node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack_node *stack)
{
	int	i;

	i = 1;
	while (stack->next != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	add_int_stack(t_stack_node *a, int argv_atoi)
{
	t_stack_node	*item;
	t_stack_node	*item_previous;

	item = create_element_stack(argv_atoi);
	item_previous = last_element(a);
	item_previous->next = item;
	item->prev = item_previous;
}
