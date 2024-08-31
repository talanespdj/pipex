/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:59:04 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/31 22:45:24 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (tstrlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	tstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*fpath(char **env, char *cmd)
{
	char	**str;
	char	*path;
	int		fd;
	int		i;

	i = 0;
	//gerer env -i
//	if (access(cmd, X_OK))
//		return (cmd);
	while (env[i])
	{
		if (env[i][4] && env[i][0] == 'P' && env[i][1] == 'A'
			&& env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
			break ;
		i++;
	}
	str = split(env[i], ':');
	i = -1;
	while (str[++i])
		str[i] = tjoin(str[i], cmd);
	i = -1;
	while (str[++i])
	{
		fd = access(str[i], X_OK);
		if (fd != -1)
			break ;
	}
	path = ft_strdup(str[i]);
	fsplit(str);
	return (path);
}

void	fsplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**prep_arg(char *str)
{
	char	**arg;
	int		i;

	i = tstrlen(str) + 1;
	arg = malloc(sizeof(char *) * 2);
	if (!arg)
		return (NULL);
	arg[0] = malloc(sizeof(char) * i);
	if (!arg[0])
		return (NULL);
	arg[0][--i] = '\0';
	arg[1] = NULL;
	while (--i >= 0)
		arg[0][i] = str[i];
	return (arg);
}

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
	free(str);
	return (tzy);
}
