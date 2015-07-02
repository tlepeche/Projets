/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 03:30:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 20:10:52 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		check_pwd(char **env)
{
	char	*title;
	int		i;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "PWD=") == 0)
		{
			free(title);
			return (1);
		}
		free(title);
		i++;
	}
	return (0);
}

int		find_missing(char **env)
{
	int	i;

	i = 0;
	if (check_pwd(env) == 0)
		i++;
	if (check_oldpwd(env) == 0)
		i += 2;
	return (i);
}

char	**check_env(char **env, int i, int find)
{
	if (find == 1 || find == 3)
	{
		env[i] = ft_strdup("PWD=");
		i++;
	}
	if (find == 2 || find == 3)
	{
		env[i] = ft_strdup("OLDPWD=");
		i++;
	}
	env[i] = NULL;
	return (env);
}

int		search_missing(char **env)
{
	int	i;

	i = 0;
	if (check_pwd(env) == 0)
		i++;
	if (check_oldpwd(env) == 0)
		i++;
	return (i);
}

char	**create_env(char **env)
{
	char	**new_env;
	int		i;
	int		j;
	int		find;

	i = 0;
	while (env[i])
		i++;
	if ((j = search_missing(env)) != 0)
	{
		new_env = (char **)malloc(sizeof(char *) * (i + j + 1));
		i = 0;
		find = find_missing(env);
		while (env[i])
		{
			new_env[i] = ft_strdup(env[i]);
			free(env[i]);
			i++;
		}
		free(env);
		new_env = check_env(new_env, i, find);
		return (new_env);
	}
	else
		return (env);
}
