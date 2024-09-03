/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:45:03 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/03 13:09:06 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	first(struct ppx *ppx)
{
	ppx->path = fpath(ppx->env, ppx->data->cmd1[0]);
	execve(ppx->path, ppx->data->cmd1, ppx->env);

}

static void	second(struct ppx *ppx)
{
	ppx->path = fpath(ppx->env, ppx->data->cmd2[0]);
	execve(ppx->path, ppx->data->cmd2, ppx->env);
}

void	cute(struct ppx *ppx)
{
	first(ppx);
	second(ppx);
}
