/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_free_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:36:15 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/11 12:36:15 by bedantas         ###   ########.fr       */
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
	t_stack_node	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	free_split(argv_split);
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}

void	free_stack(t_stack_node *a)
{
	t_stack_node	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
}

void	check_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}
