/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_last_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 20:21:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 07:13:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			find_underscore(char **env)
{
	int		i;
	char	*title;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "_=") == 0)
		{
			free(title);
			return (i);
		}
		free(title);
		i++;
	}
	return (-1);
}

static char	**create_new_env(char **env, char *str)
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
	free(env);
	new_env[i] = ft_strjoin("_=", str);
	new_env[i + 1] = NULL;
	return (new_env);
}

char		**add_last_exec(char **env, char *str)
{
	int		i;
	char	**new_env;

	i = find_underscore(env);
	if (i == -1)
	{
		new_env = create_new_env(env, str);
		return (new_env);
	}
	else
	{
		free(env[i]);
		env[i] = ft_strjoin("_=", str);
		return (env);
	}
}
