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

int	int_repetidos(t_stack_node *a, int argv_atoi)
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

t_stack_node	*criar_pilha_a(t_stack_node *a, int argc, char **argv)
{
	int		i;
	char	**argv_split;
	long	argv_atoi;

	i = 0;
	argv_split = tratar_input(argc, argv);
	if (!argv_split)
		check_error();
	while (argv_split[i])
	{
		argv_atoi = ft_atoi(argv_split[i]);
		if ((argv_atoi > INT_MAX || argv_atoi < INT_MIN)
			|| (int_repetidos(a, (int)argv_atoi)))
			free_all(argv_split, a);
		if (a == NULL)
			a = criar_elemento_pilha((int)argv_atoi);
		else
			adicionar_int_pilha(a, (int)argv_atoi);
		if (!a)
			free_all(argv_split, a);
		i++;
	}
	index_elemento(&a);
	free_split(argv_split);
	return (a);
}
