/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:38 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/23 22:33:21 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	pipex(struct pip *ppx, char **argv, char **env)
{
	char	**str;
	int		i;

	(void)argv;
	(void)ppx;
	i = 0;
	str = fpath(env);
	while (str[i])
	{
		printf("%s\n", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct pip	ppx;

	if (argc == 5)
		pipex(&ppx, argv, envp);
	return (0);
}
