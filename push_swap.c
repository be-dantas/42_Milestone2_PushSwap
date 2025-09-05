/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:11:02 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/05 18:26:19 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;

	a = NULL;
	if (argc == 2 && !argv[1][0])
		ft_putstr_fd("Error\n", 2);
	if (argc >= 2)
	{
		a = criar_pilha_a(a, argc, argv);

		t_stack_node *head = a;
		while (head != NULL)
		{
			printf ("%d\n", head->value);
			head = head->next;
		}
		
	}
	free_stack(a);
	return (0);
}
