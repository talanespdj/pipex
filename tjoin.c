/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tjoin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:28:30 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/26 23:40:01 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*tjoin(char *str, char *add)
{
	char	*tzy;
	int		i;
	int		r;
	int		t;

	i = 0;
	t = 0;
	r = tstrlen(add) + tstrlen(str);
	tzy = malloc(sizeof(char) * (tstrlen(add) + tstrlen(str) + 1));
	if (!tzy)
		return (NULL);
	while (str[i] != '\0')
	{
		tzy[i] = str[i];
		i++;
	}
	while (add[t] != '\0')
	{
		tzy[i + t] = add[t];
		t++;
	}
	tzy[i + t] = '\0';
	return(tzy);
}
