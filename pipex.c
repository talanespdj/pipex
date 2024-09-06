/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/05 21:32:08 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	pipex(struct ppx *ppx, char **argv, char **env)
{
	everinit(ppx, argv, env);
	if (pipe(ppx->fd) == -1)
		wgas("pipe failed // 1");
	ppx->pid = fork();
	printf("hohoho voici mon pid %d\n", ppx->pid);
	if (ppx->pid == -1)
		wgas("fork failed // 2");
	if (ppx->pid == 0)
		exe(ppx);
	waitpid(ppx->pid, NULL, 0);
	cute(ppx);
}

int	main(int argc, char **argv, char **envp)
{
	struct ppx	ppx;

	if (argc != 5 || !envp[0])
		wgas("not enough args || invalid env");
	else
	{
		pipex(&ppx, argv, envp);
		freeve(&ppx);
	}
	return (0);
}
