/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:11:02 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/09 14:41:39 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if ((argc == 2 && !argv[1][0]) || (argc < 2))
		ft_putstr_fd("Error\n", 2);
	if (argc >= 2)
	{
		a = criar_pilha_a(a, argc, argv);

		pilha_b(&a, &b);

		printf("Lista A:\n");
		t_stack_node *head = a;
		while (head != NULL)
		{
			printf ("%d\n", head->index);
			head = head->next;
		}

		printf("Lista B:\n");
		t_stack_node *head_1 = b;
		while (head_1 != NULL)
		{
			printf ("%d\n", head_1->index);
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



// ---- index lista A
// index_elemento(&a);

// t_stack_node *head = a;
// while (head != NULL)
// {
// 	printf ("Value: %d  Index: %d\n", head->value, head->index);
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




// ---- rotacionar pilha A
// printf("pilha A antes:\n");
// t_stack_node *head = a;
// while (head != NULL)
// {
// 	printf ("%d\n", head->value);
// 	head = head->next;
// }

// rra(&a);
// printf("pilha A depois:\n");
// t_stack_node *head_1 = a;
// while (head_1 != NULL)
// {
// 	printf ("%d\n", head_1->value);
// 	head_1 = head_1->next;
// }




// ---- rotacionar pilha A e B para cima
// pb(&b, &a);
// pb(&b, &a);
// pb(&b, &a);

// printf("pilha A com 3 pushs:\n");
// t_stack_node *head_a = a;
// while (head_a != NULL)
// {
// 	printf ("%d\n", head_a->value);
// 	head_a = head_a->next;
// }

// printf("pilha B com 3 pushs:\n");
// t_stack_node *head_b = b;
// while (head_b != NULL)
// {
// 	printf ("%d\n", head_b->value);
// 	head_b = head_b->next;
// }

// rr(&a, &b);
// printf("pilha A depois rotate rr:\n");
// t_stack_node *head_a_1 = a;
// while (head_a_1 != NULL)
// {
// 	printf ("%d\n", head_a_1->value);
// 	head_a_1 = head_a_1->next;
// }

// printf("pilha B depois rotate rr:\n");
// t_stack_node *head_b_1 = b;
// while (head_b_1 != NULL)
// {
// 	printf ("%d\n", head_b_1->value);
// 	head_b_1 = head_b_1->next;
// }




// ---- rotacionar pilha A e B para baixo
// printf("pilha A com 3 pushs:\n");
// t_stack_node *head_a = a;
// while (head_a != NULL)
// {
// 	printf ("%d\n", head_a->value);
// 	head_a = head_a->next;
// }

// printf("pilha B com 3 pushs:\n");
// t_stack_node *head_b = b;
// while (head_b != NULL)
// {
// 	printf ("%d\n", head_b->value);
// 	head_b = head_b->next;
// }

// rrr(&a, &b);
// printf("pilha A depois rotate rr:\n");
// t_stack_node *head_a_1 = a;
// while (head_a_1 != NULL)
// {
// 	printf ("%d\n", head_a_1->value);
// 	head_a_1 = head_a_1->next;
// }

// printf("pilha B depois rotate rr:\n");
// t_stack_node *head_b_1 = b;
// while (head_b_1 != NULL)
// {
// 	printf ("%d\n", head_b_1->value);
// 	head_b_1 = head_b_1->next;
// }