/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 21:23:18 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 07:12:36 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**get_new_env(char **env, int i)
{
	char	**new_env;
	int		j;
	int		k;

	j = 0;
	while (env[j])
		j++;
	new_env = (char **)malloc(sizeof(char *) * (j + 1));
	j = 0;
	k = 0;
	while (env[j])
	{
		if (j != i)
		{
			new_env[k] = ft_strdup(env[j]);
			j++;
			k++;
		}
		else
			j++;
		free(env[j - 1]);
	}
	free(env);
	new_env[k] = NULL;
	return (new_env);
}

int		find_value(char **env, char *str)
{
	int		i;
	char	*title;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		free(title);
		title = ft_strsub(title, 0, ft_strlen(title) - 1);
		if (ft_strcmp(title, str) == 0)
		{
			free(title);
			return (i);
		}
		free(title);
		i++;
	}
	return (-1);
}

char	**copy_env(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	new_env[i] = NULL;
	free(env);
	return (new_env);
}

char	**unset_env(char **env, char **av, int ac)
{
	int		a;
	int		i;
	char	**new_env;

	a = 0;
	new_env = copy_env(env);
	if (ac < 2)
		ft_putendl("unsetenv : Too few arguments");
	else
	{
		while (av[++a])
		{
			i = find_value(new_env, av[a]);
			if (i != -1)
				new_env = get_new_env(new_env, i);
		}
		new_env = add_last_exec(new_env, "unsetenv");
		return (new_env);
	}
	return (env);
}
