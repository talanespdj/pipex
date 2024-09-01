/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgas.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:43:53 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/31 22:45:07 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	wgas(char *str)
{
	perror(str);
	exit(1);
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

char	*first_path(char *str)
{
	char	*path;
	int	i;
	int	r;

	r = 0;
	i = 5;
	path = malloc(sizeof(char) * tstrlen(str) - 4);
	if (!path)
		return (NULL);
	while (str[i])
	{
		path[r] = str[i];
		i++;
		r++;
	}
	path[r] = '\0';
	return (path);
}