/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:31:44 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/31 22:48:37 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct ppx
{
	struct var	*data;
	char		*path;
}			t_ppx;

typedef struct var
{
	char		*cmd1;
	char		*cmd2;
	char		*in;
	char		*out;
}			t_data;

typedef struct spt
{
	const char	*str;
	char		**split;
	char		c;
	int			nb_words;
	int			indic;
	int			len;
	int			op;
	int			i;
}			t_split;

int				pipex(struct ppx *ppx, char **argv, char **env);

void			everinit(struct ppx *ppx, char **argv, char **env);

void			cute(struct ppx *ppx);

char			**split(char const *str, char c);

int				tstrlen(char *str);
char			*ft_strdup(char *src);
char			*fpath(char **env, char *cmd);
void			fsplit(char **str);
char			**prep_arg(char *str);

char			*tjoin(char *str, char *add);

void			wgas(char *str);
void			wegotasplituation(struct spt x);
#endif
