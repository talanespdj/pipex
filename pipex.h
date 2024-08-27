/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:31:44 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/27 14:31:01 by tespandj         ###   ########.fr       */
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

typedef struct pip
{
	struct var	*data;
}			t_pip;

typedef struct var
{
	char		*cmd_1;
	char		*cmd_2;
	char		*file_1;
	char		*file_2;
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

int				pipex(struct pip *ppx, char **argv, char **env);

char			**split(char const *str, char c);

int			tstrlen(char *str);
char			*ft_strdup(char *src);
char			*fpath(char **env, char *cmd);
void			fsplit(char **str);
char			**prep_arg(char *str);
void			wegotasplituation(struct spt x);

char			*tjoin(char *str, char *add);

int	tncmp(const char *s1, const char *s2, size_t n);

#endif
