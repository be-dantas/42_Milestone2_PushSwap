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

t_stack_node	*ultimo_elemento(t_stack_node *a)
{
	while (a->next != NULL)
		a = a->next;
	return (a);
}

int	tamanho_pilha(t_stack_node *pilha)
{
	int	i;

	i = 1;
	while (pilha->next != NULL)
	{
		i++;
		pilha = pilha->next;
	}
	return (i);
}

void	adicionar_int_pilha(t_stack_node *a, int argv_atoi)
{
	t_stack_node	*item;
	t_stack_node	*item_anterior;

	item = criar_elemento_pilha(argv_atoi);
	item_anterior = ultimo_elemento(a);
	item_anterior->next = item;
	item->prev = item_anterior;
}
