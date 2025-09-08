/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   criando_pilha_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:24:40 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 11:18:04 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*criar_elemento_pilha(int argv_atoi)
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

t_stack_node	*elemento_anterior(t_stack_node *a)
{
	while (a->next != NULL)
		a = a->next;
	return (a);
}

void	adicionar_int_pilha(t_stack_node *a, int argv_atoi)
{
	t_stack_node	*item;
	t_stack_node	*item_anterior;

	item = criar_elemento_pilha(argv_atoi);
	item_anterior = elemento_anterior(a);
	item_anterior->next = item;
	item->prev = item_anterior;
}
