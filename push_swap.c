/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:11:02 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 18:48:05 by bedantas         ###   ########.fr       */
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

		rra(&a);
		printf("pilha A depois:\n");
		t_stack_node *head_1 = a;
		while (head_1 != NULL)
		{
			printf ("%d\n", head_1->value);
			head_1 = head_1->next;
		}
		
	}
	free_stack(a);
	free_stack(b);
	return (0);
}





// ---- printar lista A
// t_stack_node *head = a;
// while (head != NULL)
// {
// 	printf ("%d\n", head->value);
// 	head = head->next;
// }





// ---- printar o prev depois de acoes push 
// printf("pilha A antes:\n");
// t_stack_node *head = a;
// while (head != NULL)
// {
// 	if (head->prev)
// 		printf("valor: %d | prev: %d\n", head->value, head->prev->value);
// 	else
// 		printf("valor: %d | prev: (NULL)\n", head->value);
// 	head = head->next;
// }

// pb(&b, &a);
// printf("pilha A depois:\n");
// t_stack_node *head_1 = a;
// while (head_1 != NULL)
// {
// 	if (head_1->prev)
// 		printf("valor: %d | prev: %d\n", head_1->value, head_1->prev->value);
// 	else
// 		printf("valor: %d | prev: (NULL)\n", head_1->value);
// 	head_1 = head_1->next;
// }

// printf("pilha B:\n");
// t_stack_node *head_2 = b;
// while (head_2 != NULL)
// {
// 	if (head_2->prev)
// 		printf("valor: %d | prev: %d\n", head_2->value, head_2->prev->value);
// 	else
// 		printf("valor: %d | prev: (NULL)\n", head_2->value);
// 	head_2 = head_2->next;
// }





// ---- printar o prev depois de acoes swap
// printf("pilha A antes:\n");
// t_stack_node *head = a;
// while (head != NULL)
// {
// 	if (head->prev)
// 		printf("valor: %d | prev: %d\n", head->value, head->prev->value);
// 	else
// 		printf("valor: %d | prev: (NULL)\n", head->value);
// 	head = head->next;
// }

// sa(&a);
// printf("pilha A depois:\n");
// t_stack_node *head_1 = a;
// while (head_1 != NULL)
// {
// 	if (head_1->prev)
// 		printf("valor: %d | prev: %d\n", head_1->value, head_1->prev->value);
// 	else
// 		printf("valor: %d | prev: (NULL)\n", head_1->value);
// 	head_1 = head_1->next;
// }