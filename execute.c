/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:45:03 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 01:31:13 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	exe(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	printf("JE rentre dans la fonctiont EXEEEEEEEE\n");
	tfd = open (ppx->in, O_RDONLY, 0777);
	if (tfd == -1)
		wgas("exec.c // l.20   open fd fail");
	printf("\t Ainsi j'exe la commande %s\n\n", ppx->cmd1[0]);
	dup2(ppx->fd[0], STDOUT_FILENO);
//////////// le programe kill ici pour le processus enfant
	dup2(tfd, STDIN_FILENO);
	close(tfd);
	close(ppx->fd[1]);
	path = fpath(ppx->env, ppx->cmd1[0], -1);
	if (!path)
	{
		fsplit(ppx->cmd1);
		fsplit(ppx->cmd2);
		free(path);
		exit(42);
	}
	if (execve(path, ppx->cmd1, ppx->env) == -1)
	{
		fsplit(ppx->cmd1);
		fsplit(ppx->cmd2);
		free(path);
		exit(42);
	}
}

void	cute(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	printf("JE rentre dans la fonctiont CUTEEEEEEE\n");
	tfd = open (ppx->out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (tfd == -1)
		wgas("exec.c // l.20   open fd fail");
	dup2(ppx->fd[1], STDIN_FILENO);
	printf("\t Enfin je cute la commande %s\n\n", ppx->cmd2[0]);
	dup2(tfd, STDOUT_FILENO);
	close(tfd);
//////////// le programe kill ici pour le processus parent
	close(ppx->fd[0]);
	path = fpath(ppx->env, ppx->cmd1[0], -1);
	if (!path)
	{
		fsplit(ppx->cmd1);
		fsplit(ppx->cmd2);
		free(path);
		exit(84);
	}
	if (execve(path, ppx->cmd1, ppx->env) == -1)
	{
		fsplit(ppx->cmd1);
		fsplit(ppx->cmd2);
		free(path);
		exit(84);
	}
}
