/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:11:02 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 17:49:32 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	
	if (argc == 2 && !argv[1][0])
		ft_putstr_fd("Error\n", 2);
	if (argc >= 2)
	{
		a = criar_pilha_a(a, argc, argv);

		printf("pilha A antes:\n");
		t_stack_node *head = a;
		while (head != NULL)
		{
			printf ("%d\n", head->value);
			head = head->next;
		}
		printf("pilha A depois:\n");
		pb(&b, &a);	
		t_stack_node *head_1 = a;
		while (head_1 != NULL)
		{
			printf ("%d\n", head_1->value);
			head_1 = head_1->next;
		}
		printf("pilha B:\n");
		t_stack_node *head_2 = b;
		while (head_2 != NULL)
		{
			printf ("%d\n", head_2->value);
			head_2 = head_2->next;
		}
		
	}
	free_stack(a);
	free_stack(b);
	return (0);
}






// t_stack_node *head = a;
// while (head != NULL)
// {
// 	printf ("%d\n", head->value);
// 	head = head->next;
// }