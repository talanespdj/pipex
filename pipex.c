/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/29 18:54:59 by tespandj         ###   ########.fr       */
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

	if (argc == 5)
		pipex(&ppx, argv, envp);
	return (0);
}
