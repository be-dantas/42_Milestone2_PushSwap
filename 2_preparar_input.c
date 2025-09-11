/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparar_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:16:59 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/08 17:48:34 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*fazer_join(char **argv, char *argv_join)
{
	int		i;
	char	*temp;
	char	*joined;

	i = 1;
	while (argv[i])
	{
		temp = ft_strjoin(argv[i], " ");
		if (!temp)
		{
			free (argv_join);
			return (NULL);
		}
		joined = ft_strjoin(argv_join, temp);
		free(argv_join);
		free(temp);
		if (!joined)
			return (NULL);
		argv_join = joined;
		i++;
	}
	return (argv_join);
}

char	*argv_maior_2(char **argv)
{
	int		i;
	char	*argv_ok;
	char	*argv_join;

	i = 1;
	argv_ok = ft_strdup("");
	if (!argv_ok)
		return (NULL);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			free (argv_ok);
			check_error();
		}
		i++;
	}
	argv_join = fazer_join(argv, argv_ok);
	return (argv_join);
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
