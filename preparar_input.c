/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparar_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:16:59 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/05 18:17:33 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// se o input vier separado: ./a.out "1" "2" "3"
char	*argv_maior_2(char **argv)
{
	int		i;
	char	*argv_ok;
	char	*temp;

	i = 1;
	argv_ok = ft_strdup("");
	temp = ft_strdup("");
	if (!temp || !argv_ok)
		return (NULL);
	while (argv[i])
	{
		temp = ft_strjoin(argv[i], " ");
		argv_ok = ft_strjoin(argv_ok, temp);
		if (!temp || !argv_ok)
		{
			free (temp);
			free (argv_ok);
			return (NULL);
		}
		i++;
	}
	free (temp);
	return (argv_ok);
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

// checa cada string do array para ver 'e numero ou se tem ++ -- seguidos
int	input_valido(char *argv_ok)
{
	int	i;

	i = 0;
	while (argv_ok[i])
	{
		if (argv_ok[i] == ' ')
		{
			i++;
			continue ;
		}
		if (argv_ok[i] == '+' || argv_ok[i] == '-')
		{
			if (argv_ok[i + 1] == '\0')
				return (0);
			if (i > 0 && argv_ok[i - 1] != ' ')
				return (0);
			if (!ft_isdigit(argv_ok[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(argv_ok[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**tratar_input(int argc, char **argv)
{
	char	*argv_ok;
	char	**argv_split;

	argv_ok = NULL;
	argv_split = NULL;
	if (argc > 2)
		argv_ok = argv_maior_2(argv);
	else if (argc == 2)
		argv_ok = ft_strdup(argv[1]);
	if (!argv_ok)
		return (NULL);
	if (!input_valido(argv_ok))
	{
		free (argv_ok);
		return (NULL);
	}
	argv_split = ft_split(argv_ok, ' ');
	if (!argv_split)
	{
		free (argv_ok);
		return (NULL);
	}
	free (argv_ok);
	return (argv_split);
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
	free_split(argv_split);
	return (a);
}
