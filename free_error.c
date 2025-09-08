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

void	free_split(char **argv_split)
{
	int	i;

	if (!argv_split)
		return ;
	i = 0;
	while (argv_split[i])
	{
		free(argv_split[i]);
		i++;
	}
	free(argv_split);
}

void	free_all(char **argv_split, t_stack_node *a)
{
	t_stack_node	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	free_split(argv_split);
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}

void	free_stack(t_stack_node *a)
{
	t_stack_node	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

void	check_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}
