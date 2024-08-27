char	*fpath(char **env, char *cmd)
{
	char	**str;
	char	*path;
	int	i;

	i = 0;
	(void)cmd;
	path = NULL; 
//	if (access(cmd, X_OK) != -1)
//	{
//		printf("%s\n", cmd);
//		return (cmd);
//	}
	while (env[i])
	{
		if (env[i][4] && env[i][0] == 'P' && env[i][1] == 'A'
			&& env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
			break;
		i++;
	}
	str = split(env[i], ':');
	printf("%s\n", str[i]);
	return (str[i]);
/*	i = 0;
	while (str[i])
	{
		str[i] = tjoin(str[i], cmd);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (access(str[i], X_OK))
		{
			path = str[i];
			break;
		}
		i++;
	}
	fsplit(str);
	printf("%s\n", path);
	return (path);*/
}
