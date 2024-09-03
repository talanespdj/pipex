/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/03 22:52:26 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	pipex(struct ppx *ppx, char **argv, char **env)
{
	everinit(ppx, argv, env);
	if (pipe(ppx->fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct ppx	ppx;
	pid_t		pid;

	if (argc != 5 || !envp[0])
		wgas("not enough args // invalid env");
	else
	{
		pipex(&ppx, argv, envp);
		freeve(&ppx);
	}
	return (0);
}
