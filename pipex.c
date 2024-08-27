/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/27 15:00:03 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	pipex(struct pip *ppx, char **argv, char **env)
{
	char	*path;
	char	**ex_arg;

	(void)ppx;
	if (!access(argv[2], X_OK))
		path = fpath(env, argv[2]);
	else
		path = ft_strdup(argv[2]);
	if (path == NULL)
		return (0);
	ex_arg = prep_arg(argv[2]);
	execve(path, ex_arg, env);
	free(ex_arg[0]);
	free(ex_arg[1]);
	free(ex_arg);
	free(path);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct pip	ppx;

	if (argc == 5)
		pipex(&ppx, argv, envp);
	return (0);
}
