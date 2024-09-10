/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/10 18:56:44 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	pipex(struct ppx *ppx, char **argv, char *const *env)
{
	everinit(ppx, argv, (char **)env);
	if (pipe(ppx->fd) == -1)
		wgas("");
	ppx->pid1 = fork();
	if (ppx->pid1 == -1)
		wgas("");
	if (ppx->pid1 == 0)
	{
		printf("Je rentre dans l'exe\n");
		exe(ppx);
	}
	ppx->pid1 = fork();
	if (ppx->pid1 == -1)
		wgas("");
	if (ppx->pid1 == 0)
	{
		printf("Je rentre dans l'cute\n");
		cute(ppx);
	}
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	waitpid(ppx->pid1, NULL, 0);
	waitpid(ppx->pid1, NULL, 0);
}

int	main(int argc, char **argv, char *const *envp)
{
	struct ppx	ppx;

	if (argc != 5)
		wgas("not enough args");
	else
	{
		pipex(&ppx, argv, envp);
		freeve(&ppx);
	}
	return (0);
}
