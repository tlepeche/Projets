/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 07:14:48 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 09:19:10 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	find_home(char **env)
{
	int		i;
	char	*title;

	i = 0;
	while (env[i])
	{
		title = ft_strrevchr(env[i], '=');
		if (ft_strcmp(title, "HOME=") == 0)
		{
			free(title);
			return (i);
		}
		free(title);
		i++;
	}
	return (-1);
}

static char	*check_home(char **env)
{
	char	*pwd;
	char	*home;
	char	*env_home;
	int		i;

	pwd = (char *)malloc(sizeof(char) * 1024);
	pwd = getcwd(pwd, 1024);
	i = find_home(env);
	if (i != -1)
	{
		env_home = ft_strsub(env[i], 5, ft_strlen(env[i]));
		home = ft_strjoin("/Volumes/Data", env_home);
		free(env_home);
		if (ft_strstr(pwd, home) != NULL)
		{
			free(pwd);
			pwd = ft_strsub(pwd, ft_strlen(home), ft_strlen(pwd));
			free(pwd);
			pwd = ft_strjoin("~", pwd);
		}
		free(home);
	}
	return (pwd);
}

void		display_prompt(char **env)
{
	char	*path;

	ft_putstr("[");
	ft_putstr("\033[1;31m");
	ft_putstr("tlepeche");
	ft_putstr("\033[0;37m");
	ft_putstr(" in ");
	path = check_home(env);
	ft_putstr("\033[1;36m");
	ft_putstr(path);
	ft_putstr("\033[0;37m");
	ft_putstr("] > ");
	free(path);
}
