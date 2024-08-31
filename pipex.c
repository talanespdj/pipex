/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/31 22:49:14 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	pipex(struct ppx *ppx, char **argv, char **env)
{
	char	*path;

	(void)ppx;
	everinit(ppx, argv, env);
	ppx->path = fpath(env, argv[2]);
	if (ppx->path == NULL)
		return (0);
	cute(ppx);
	execve(path, prep_arg(argv[2]), env);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct ppx	ppx;
	int		fd;

	if (argc != 5)
		wgas("not enough args");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			wgas("infile not valid / fd <= 0");
		close(fd);
		fd = open(argv[4], O_RDONLY);
		if (fd <= 0)
			wgas("outfile not valid / fd <= 0");
		close(fd);
		pipex(&ppx, argv, envp);
	}
	return (0);
}
