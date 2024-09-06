/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:42:10 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/05 21:07:24 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	everinit(struct ppx *ppx, char **argv, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		wgas("infile not valid / fd <= 0");
	close(fd);
	ppx->in = argv[1];
	ppx->cmd1 = split(argv[2], ' ');
	ppx->cmd2 = split(argv[3], ' ');
	ppx->out = argv[4];
	ppx->env = env;
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

void	freeve(struct ppx *ppx)
{
	fsplit(ppx->cmd1);
	fsplit(ppx->cmd2);
	free(ppx->fd);
	exit(0);
}

void	fsplit(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	wgas(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
