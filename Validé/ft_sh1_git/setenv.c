/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 21:22:09 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/05 01:52:36 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char	**create_new_env(char **env, char **av)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	new_env[i] = ft_strjoin(av[1], "=");
	if (av[2])
	{
		free(new_env[i]);
		new_env[i] = ft_strjoin(new_env[i], av[2]);
	}
	new_env[i + 1] = NULL;
	free(env);
	return (new_env);
}

char		**new_env(char **av, char **env, int i, int find)
{
	if (find == 1)
	{
		ft_bzero(env[i], ft_strlen(env[i]));
		free(env[i]);
		env[i] = ft_strjoin(av[1], "=");
		if (av[2])
		{
			free(env[i]);
			env[i] = ft_strjoin(env[i], av[2]);
		}
	}
	else
		env = create_new_env(env, av);
	return (env);
}

char		**change_env(char **env, char **av, int find)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i])
	{
		str = ft_strrevchr(env[i], '=');
		free(str);
		str = ft_strsub(str, 0, ft_strlen(str) - 1);
		if (ft_strcmp(str, av[1]) == 0)
		{
			free(str);
			find = 1;
			break ;
		}
		free(str);
		i++;
	}
	env = new_env(av, env, i, find);
	return (env);
}

char		**set_env(char **env, int ac, char **av)
{
	int		find;

	find = 0;
	if (ac > 3)
		ft_putendl("setenv: Too many arguments.");
	else if (ac == 1)
		env = manage_env(env, ac, av);
	else
		env = change_env(env, av, find);
	return (env);
}
