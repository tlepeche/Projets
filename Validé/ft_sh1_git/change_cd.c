/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 16:25:26 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 09:17:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		check_oldpwd(char **env)
{
	char	*title;
	int		i;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "OLDPWD=") == 0)
		{
			free(title);
			return (1);
		}
		free(title);
		i++;
	}
	return (0);
}

char	*get_home(char **env)
{
	char	*home;
	char	*title;
	int		i;
	int		find;

	i = -1;
	find = 0;
	while (env[++i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "HOME=") == 0)
		{
			free(title);
			find = 1;
			break ;
		}
		free(title);
	}
	if (find == 0)
		ft_putendl_fd("cd : HOME not set", 2);
	if (find == 0 || ft_strcmp(env[i], "HOME=") == 0)
		home = ft_strdup(".");
	else
		home = ft_strsub(env[i], 5, ft_strlen(env[i]));
	return (home);
}

char	*move_home(char **av, char **env)
{
	char	*dir;
	char	*tmp_av;

	dir = get_home(env);
	tmp_av = ft_strsub(av[1], 1, ft_strlen(av[1]));
	free(dir);
	dir = ft_strjoin(dir, tmp_av);
	free(tmp_av);
	return (dir);
}

char	*switch_pwd(char **av, char **env)
{
	char	*dir;
	int		len;
	int		i;
	int		j;

	j = 0;
	while (env[j])
		j++;
	i = find_oldpwd(env);
	if (j == i)
	{
		ft_putstr_fd("cd : OLDPWD not set", 2);
		dir = ft_strdup(".");
	}
	else
	{
		dir = ft_strrchr(env[i], '=');
		len = ft_strlen(dir);
		dir = (dir[1] == 0) ? ft_strdup(".") : ft_strsub(dir, 1, len);
		if (av[1][2] == '/' && av[1][3] != '\0')
			dir = complete_dir(dir, av[1]);
	}
	return (dir);
}
