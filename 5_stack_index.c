/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:47:03 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 17:48:52 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_elemento(t_stack_node **a)
{
	int				i;
	t_stack_node	*temp_pilha;
	t_stack_node	*percorrer;
	t_stack_node	*inicial_temp;

	i = 0;
	temp_pilha = *a;
	percorrer = *a;
	inicial_temp = temp_pilha;
	while (temp_pilha != NULL)
	{
		while (percorrer != NULL)
		{
			if (temp_pilha->value > percorrer->value)
				i++;
			percorrer = percorrer->next;
		}
		temp_pilha->index = i;
		i = 0;
		temp_pilha = temp_pilha->next;
		percorrer = *a;
	}
	*a = inicial_temp;
}
