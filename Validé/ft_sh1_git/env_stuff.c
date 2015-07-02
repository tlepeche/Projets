/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 08:58:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/14 06:55:51 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**cpy(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

char	**destroy_env(char **env)
{
	char	**new_env;

	free_tab(env);
	new_env = (char **)malloc(sizeof(char *) * 1);
	new_env[0] = NULL;
	return (new_env);
}

int		find_val(char **env, char *str)
{
	int		i;
	char	*search;
	char	*env_val;

	i = 0;
	search = ft_strrevchr(str, '=');
	while (env[i])
	{
		env_val = ft_strrevchr(env[i], '=');
		if (ft_strcmp(env_val, search) == 0)
		{
			free(env_val);
			free(search);
			return (i);
		}
		free(env_val);
		i++;
	}
	free(search);
	return (-1);
}

char	**add_var_env(char **env, char *str)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	while (env[i])
		i++;
	j = find_val(env, str);
	i = (j == -1) ? i + 2 : i + 1;
	new_env = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while (env[++i])
	{
		new_env[i] = (i == j) ? ft_strdup(str) : ft_strdup(env[i]);
		free(env[i]);
	}
	if (j == -1)
	{
		new_env[i] = ft_strdup(str);
		new_env[i + 1] = NULL;
	}
	else
		new_env[i] = NULL;
	free(env);
	return (new_env);
}

char	**create_nav(char **av, int ac, int i, t_restart *r)
{
	int		j;
	char	**new_av;

	r->exec = 0;
	r->stop = 0;
	r->test = 0;
	j = 0;
	new_av = (char **)malloc(sizeof(char *) * (ac + 1));
	while (av[i])
	{
		new_av[j] = ft_strdup(av[i]);
		i++;
		j++;
	}
	new_av[j] = NULL;
	return (new_av);
}
