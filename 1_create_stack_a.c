/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_criar_pilha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:50 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/11 12:35:50 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_element(t_stack_node **a)
{
	int				i;
	t_stack_node	*temp_stack;
	t_stack_node	*i_stack;
	t_stack_node	*initial_temp;

	i = 0;
	temp_stack = *a;
	i_stack = *a;
	initial_temp = temp_stack;
	while (temp_stack != NULL)
	{
		while (i_stack != NULL)
		{
			if (temp_stack->value > i_stack->value)
				i++;
			i_stack = i_stack->next;
		}
		temp_stack->index = i;
		i = 0;
		temp_stack = temp_stack->next;
		i_stack = *a;
	}
	*a = initial_temp;
}

int	int_repeated(t_stack_node *a, int argv_atoi)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == argv_atoi)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack_node	*create_stack_a(t_stack_node *a, int argc, char **argv)
{
	int		i;
	char	**argv_split;
	long	argv_atoi;

	i = 0;
	argv_split = treat_input(argc, argv);
	if (!argv_split)
		check_error();
	while (argv_split[i])
	{
		argv_atoi = ft_atoi(argv_split[i]);
		if ((argv_atoi > INT_MAX || argv_atoi < INT_MIN)
			|| (int_repeated(a, (int)argv_atoi)))
			free_all(argv_split, a);
		if (a == NULL)
			a = create_element_stack((int)argv_atoi);
		else
			add_int_stack(a, (int)argv_atoi);
		if (!a)
			free_all(argv_split, a);
		i++;
	}
	index_element(&a);
	free_split(argv_split);
	return (a);
}

int	stack_order_ok(t_stack_node *a)
{
	while (a && a->next)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (0);
	}
	return (1);
}
