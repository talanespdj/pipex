/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:59:04 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/27 00:01:18 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	tstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**fpath(char **env)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (env[i])
	{
		if (env[i][4] && env[i][0] == 'P' && env[i][1] == 'A'
			&& env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
			return (split(env[i], ':'));
		i++;
	}
	exit(EXIT_FAILURE);
}

char	**prep_arg(char *str)
{
	char	**arg;
	int		i;

	i = tstrlen(str) + 1;
	arg = malloc(sizeof(char *) * 2);
	if (!arg)
		return (NULL);
	arg[0] = malloc(sizeof(char) * i);
	if (!arg[0])
		return (NULL);
	arg[0][i] = '\0';
	arg[1] = NULL;
	while (--i >= 0)
		arg[0][i] = str[i];
	return (arg);
}

void	wegotasplituation(struct spt x)
{
	int	i;

	i = 0;
	while (x.split[i] && i <= x.op)
	{
		free(x.split[i]);
		i++;
	}
	free(x.split);
}
