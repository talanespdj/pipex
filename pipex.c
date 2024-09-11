/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/11 20:57:54 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	pipex(struct ppx *ppx, char **argv, char *const *env)
{
	everinit(ppx, argv, (char **)env);
	if (pipe(ppx->fd) == -1)
		wgas("");
	ppx->pid1 = fork();
	if (ppx->pid1 == -1)
		wgas("");
	if (ppx->pid1 == 0)
		exe(ppx);
	ppx->pid2 = fork();
	if (ppx->pid2 == -1)
		wgas("");
	if (ppx->pid2 == 0)
		cute(ppx);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	waitpid(ppx->pid1, NULL, 0);
	waitpid(ppx->pid2, NULL, 0);
}

int	main(int argc, char **argv, char *const *envp)
{
	struct ppx	ppx;

	if (argc != 5)
	{
//		putstr("need ./pipex + 4 args\n");
//		exit(EXIT_FAILURE);
		wgas("need ./pipex + 4 args\n");
	}
	else
	{
		pipex(&ppx, argv, envp);
		fsplit(ppx.cmd1);
		fsplit(ppx.cmd2);
	}
	return (0);
}
