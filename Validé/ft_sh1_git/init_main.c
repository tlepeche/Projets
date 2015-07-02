/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 06:54:52 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/22 02:34:19 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**init(char *line, char **env, t_restart *r)
{
	int		ac;
	char	**av;
	int		i;

	ac = 0;
	av = ft_strsplit_blank(line);
	while (av[ac])
		ac++;
	if (ac != 0)
		env = analyse_line(ac, av, env, r);
	if (r->stop == 1)
	{
		ft_putendl("exit");
		exit(0);
	}
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (env);
}

int		find_var_env(char **env, char *str)
{
	int		i;
	char	*search;

	i = 0;
	while (env[i])
	{
		search = ft_strrevchr(env[i], '=');
		if (ft_strcmp(search, str) == 0)
		{
			free(search);
			return (i);
		}
		free(search);
		i++;
	}
	return (-1);
}

char	*shell_level(char **env, int j)
{
	int		len;
	char	*shlvl;

	len = (j != -1) ? ft_strlen(env[j]) : 0;
	shlvl = (j != -1) ? ft_strsub(env[j], 6, len) : ft_strdup("0");
	free(shlvl);
	shlvl = (ft_atoi(shlvl) < 0) ? ft_itoa(0) : ft_itoa(ft_atoi(shlvl) + 1);
	return (shlvl);
}

char	**increase_shlvl(char **env)
{
	char	**new_env;
	char	*shlvl;
	int		i;
	int		j;

	i = 0;
	while (env[i])
		i++;
	j = find_var_env(env, "SHLVL=");
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	shlvl = shell_level(env, j);
	i = 0;
	while (env[i])
	{
		new_env[i] = (i == j) ? ft_strjoin("SHLVL=", shlvl) : ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	free(env);
	new_env[i] = (j == -1) ? ft_strjoin("SHLVL=", shlvl) : NULL;
	free(shlvl);
	new_env[i + 1] = NULL;
	return (new_env);
}

char	**init_env(char **env)
{
	char	**envp;
	char	*tmp_shell;
	int		i;
	int		j;

	i = 0;
	while (env[i])
		i++;
	j = find_var_env(env, "SHELL=");
	envp = (char **)malloc(sizeof(char *) * (i + 2));
	tmp_shell = ft_strdup("SHELL=./ft_minishell1");
	i = 0;
	while (env[i])
	{
		envp[i] = (i == j) ? ft_strdup(tmp_shell) : ft_strdup(env[i]);
		i++;
	}
	envp[i] = (j == -1) ? ft_strdup(tmp_shell) : NULL;
	free(tmp_shell);
	envp[i + 1] = NULL;
	envp = increase_shlvl(envp);
	return (envp);
}
