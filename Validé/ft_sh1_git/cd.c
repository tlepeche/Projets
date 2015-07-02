/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 21:26:21 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/03 21:45:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**change_directory(char *dir, char **env, t_restart *r)
{
	int		i;
	int		j;
	char	*pwd;
	char	*old_pwd;

	if (r->recurs == 0)
		chdir(dir);
	i = find_pwd(env);
	j = find_oldpwd(env);
	old_pwd = ft_strsub(env[i], 4, ft_strlen(env[i]));
	free(env[j]);
	env[j] = ft_strjoin("OLDPWD=", old_pwd);
	pwd = (char *)malloc(sizeof(char) * 1024);
	pwd = getcwd(pwd, 1024);
	free(env[i]);
	env[i] = ft_strjoin("PWD=", pwd);
	free(pwd);
	free(old_pwd);
	return (env);
}

int		error_directory(char *dir, int granted, char **tmp_dir, t_restart *r)
{
	granted = 0;
	multi_error("cd: ", dir, 1, r);
	free(*tmp_dir);
	return (granted);
}

int		check_dir_path(char *tmp_dir, char *dir, t_restart *r)
{
	t_stat	*f_stat;

	f_stat = (t_stat *)malloc(sizeof(t_stat));
	stat(tmp_dir, f_stat);
	if (check_stat(f_stat->st_mode) == 1)
	{
		if (access(tmp_dir, X_OK) == -1)
		{
			multi_error("cd: ", dir, 2, r);
			free(tmp_dir);
			free(f_stat);
			return (0);
		}
	}
	else
	{
		multi_error("cd: ", dir, 3, r);
		free(tmp_dir);
		free(f_stat);
		return (0);
	}
	free(f_stat);
	return (1);
}

char	**check_access(char *dir, char **env, t_restart *r)
{
	char	*tmp_dir;
	int		i;
	int		j;
	int		granted;

	j = 0;
	i = how_many(dir, '/');
	while (++j <= i + 1)
	{
		tmp_dir = ft_strnchr(dir, '/', j);
		if (access(tmp_dir, F_OK) == -1)
		{
			granted = error_directory(dir, granted, &tmp_dir, r);
			break ;
		}
		else
		{
			if ((granted = check_dir_path(tmp_dir, dir, r)) == 0)
				break ;
		}
		free(tmp_dir);
	}
	if (granted == 1)
		env = change_directory(dir, env, r);
	return (env);
}

char	**move_directory(char **av, char **env, t_restart *r)
{
	char	*dir;

	if (!av[1] || (av[1][0] == '~' && av[1][1] == '\0') ||
			(ft_strcmp(av[1], "--") == 0))
		dir = get_home(env);
	else if (av[1][0] == '~' && av[1][1] == '/')
		dir = move_home(av, env);
	else if (av[1][0] == '~' && av[1][1] == '-' &&
			(av[1][2] == '\0' || av[1][2] == '/'))
		dir = switch_pwd(av, env);
	else if (av[1][0] == '-' && av[1][1] == '\0')
	{
		dir = switch_pwd(av, env);
		if (ft_strcmp(dir, ".") == 0)
			ft_putchar('\n');
		else
			ft_putendl(dir);
	}
	else
		dir = ft_strdup(av[1]);
	env = create_env(env);
	env = check_access(dir, env, r);
	free(dir);
	return (env);
}
