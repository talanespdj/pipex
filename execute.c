/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:45:03 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/11 21:56:31 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	f_exec(struct ppx *ppx, int d)
{
	if (d)
		write(2, "command not found\n", 18);
	fsplit(ppx->cmd1);
	fsplit(ppx->cmd2);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	exit(22);
}

void	exe(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	if (ppx->cmd1[0] == NULL || ppx->cmd1[1] != NULL)
		f_exec(ppx, 1);
	tfd = open(ppx->in, O_RDONLY);
	if (tfd == -1)
	{
		perror(ppx->in);
		f_exec(ppx, 0);
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
		f_exec(ppx, 1);
	if (execve(path, ppx->cmd1, ppx->env) == -1)
		f_exec(ppx, 0);
}

void	cute(struct ppx *ppx)
{
	int		tfd;
	char	*path;

	if (ppx->cmd2[0] == NULL || ppx->cmd2[1] != NULL)
		f_exec(ppx, 1);
	tfd = open(ppx->out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (tfd == -1)
	{
		perror(ppx->out);
		f_exec(ppx, 0);
	}
	if (dup2(ppx->fd[0], STDIN_FILENO) == -1)
		wgas("");
	if (dup2(tfd, STDOUT_FILENO) == -1)
		wgas("");
	close(tfd);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	path = fpath(ppx->env, ppx->cmd2[0], -1);
	if (!path)
		f_exec(ppx, 1);
	if (execve(path, ppx->cmd2, ppx->env) == -1)
		f_exec(ppx, 0);
}
