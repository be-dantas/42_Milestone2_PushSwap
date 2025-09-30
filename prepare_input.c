/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_preparar_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:59 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/11 12:35:59 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(char *argv_ok)
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

char	*make_join(char **argv, char *argv_join)
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

int	string_space(char *argv)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			flag = 1;
		if (argv[i + 1] == '\0' && flag == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*argv_up_2(char **argv)
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
		if (argv[i][0] == '\0' || string_space(argv[i]))
		{
			free (argv_ok);
			check_error();
		}
		i++;
	}
	argv_join = make_join(argv, argv_ok);
	return (argv_join);
}

char	**treat_input(int argc, char **argv)
{
	char	*argv_ok;
	char	**argv_split;

	argv_ok = NULL;
	argv_split = NULL;
	if (argc > 2)
		argv_ok = argv_up_2(argv);
	else if (argc == 2 && argv[1][0] && !string_space(argv[1]))
		argv_ok = ft_strdup(argv[1]);
	if (!argv_ok)
		return (NULL);
	if (!valid_input(argv_ok))
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
