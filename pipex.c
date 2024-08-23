/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/23 21:24:56 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	pipex(char **argv)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		return(1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	

}

int	main(int argc, char **argv, char **envp)
{
	struct pip	ppx;

	while (*envp != NULL){ printf("%s\n", *envp); envp++; }
	exit(EXIT_SUCCESS);
}


	if (argc == 5)
	{
		pipex(argv);
	}
	return (0);
}
