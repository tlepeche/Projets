/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 16:36:58 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/27 03:07:05 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		find_pwd(char **env)
{
	int		i;
	char	*title;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "PWD=") == 0)
		{
			free(title);
			break ;
		}
		free(title);
		i++;
	}
	return (i);
}

int		find_oldpwd(char **env)
{
	int		i;
	char	*title;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "OLDPWD=") == 0)
		{
			free(title);
			break ;
		}
		free(title);
		i++;
	}
	return (i);
}

char	**choose_path(char **env, int j, int i)
{
	char	*str;
	char	**path;

	if (j == 0)
	{
		path = (char **)malloc(sizeof(char *) * 2);
		path[0] = ft_strdup("/bin");
		path[1] = NULL;
	}
	else
	{
		str = ft_strsub(env[i], 5, ft_strlen(env[i]));
		path = ft_strsplit(str, ':');
		free(str);
	}
	return (path);
}

char	**get_path(char **env)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH") != NULL)
		{
			j = 1;
			break ;
		}
		i++;
	}
	path = choose_path(env, j, i);
	return (path);
}
