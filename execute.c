/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:45:03 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/10 18:02:35 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static	void	f_exec(struct ppx *ppx)
{
	fsplit(ppx->cmd1);
	fsplit(ppx->cmd2);
	write(2, "Command not found !\n", 24);
	exit(22);
}

void	exe(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	tfd = 1;
	if (tfd == -1)
	{
		perror("");
		exit(0);
	}
	if (dup2(tfd, STDIN_FILENO) == -1)
		wgas("");
	close(tfd);
	if (dup2(ppx->fd[1], STDOUT_FILENO) == -1)
		wgas("");
	close(ppx->fd[1]);
	close(ppx->fd[0]);
	path = fpath(ppx->env, ppx->cmd1[0], -1);
	if (!path)
		f_exec(ppx);
	if (execve(path, ppx->cmd1, ppx->env) == -1)
		f_exec(ppx);
}

void	cute(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	tfd = open(ppx->out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (tfd == -1)
		return (perror(""));
	if (dup2(ppx->fd[0], STDIN_FILENO) == -1)
		wgas("");
	if (dup2(tfd, STDOUT_FILENO) == -1)
		wgas("");
	close(tfd);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	path = fpath(ppx->env, ppx->cmd2[0], -1);
	if (!path)
		f_exec(ppx);
	if (execve(path, ppx->cmd2, ppx->env) == -1)
		f_exec(ppx);
}
