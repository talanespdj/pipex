/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:45:03 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 18:41:58 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static	void	f_exec(struct ppx *ppx, char *path)
{
	fsplit(ppx->cmd1);
	fsplit(ppx->cmd2);
	free(path);
	exit(22);
}

void	exe(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	tfd = open(ppx->in, O_RDONLY, 0777);
	if (tfd == -1)
		wgas("exec.c // l.20   open fd fail");
	if (dup2(tfd, STDIN_FILENO) == -1)
		wgas("l.24");
	close(tfd);
	if (dup2(ppx->fd[1], STDOUT_FILENO) == -1)
		wgas("l.28");
	close(ppx->fd[1]);
	close(ppx->fd[0]);
	path = fpath(ppx->env, ppx->cmd1[0], -1);
	if (!path)
	{
		fsplit(ppx->cmd1);
		fsplit(ppx->cmd2);
		exit(42);
	}
	if (execve(path, ppx->cmd1, ppx->env) == -1)
		f_exec(ppx, path);
}

void	cute(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	tfd = open (ppx->out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (tfd == -1)
		wgas("exec.c // l.20   open fd fail");
	if (dup2(ppx->fd[0], STDIN_FILENO) == -1)
		wgas("l.59");
	if (dup2(tfd, STDOUT_FILENO) == -1)
		wgas("l.61");
	close(tfd);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	path = fpath(ppx->env, ppx->cmd2[0], -1);
	if (!path)
	{
		fsplit(ppx->cmd1);
		fsplit(ppx->cmd2);
		exit(84);
	}
	if (execve(path, ppx->cmd2, ppx->env) == -1)
		f_exec(ppx, path);
}
