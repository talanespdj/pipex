/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:42:10 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/03 13:07:09 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	everinit(struct ppx *ppx, char **argv, char **env)
{
	ppx->data = (t_data *)malloc(sizeof(t_data));
	if (!ppx->data)
		exit(EXIT_FAILURE);
	ppx->env = env;
	ppx->data->in = argv[1];
	ppx->data->cmd1 = split(argv[2], ' ');
	ppx->data->cmd2 = split(argv[3], ' ');
	printf("%s\n", ppx->data->cmd1[0]);
	printf("%s\n", ppx->data->cmd2[0]);
	ppx->data->out = argv[4];
}
