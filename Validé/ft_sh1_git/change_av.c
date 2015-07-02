/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:48:40 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/25 06:56:48 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*change_home(char *str, char **env)
{
	char	*dir;
	char	*tmp_str;

	dir = get_home(env);
	tmp_str = ft_strsub(str, 1, ft_strlen(str));
	free(dir);
	dir = ft_strjoin(dir, tmp_str);
	free(tmp_str);
	return (dir);
}

char	**change_av(char **av, char **env)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '~' && av[i][1] == '\0')
		{
			free(av[i]);
			av[i] = get_home(env);
		}
		else if (av[i][0] == '~' && av[i][1] == '/')
		{
			free(av[i]);
			av[i] = change_home(av[i], env);
		}
		else if (av[i][0] == '~' && av[i][1] == '-' &&
				(av[i][2] == '\0' || av[i][2] == '/'))
		{
			free(av[i]);
			av[i] = switch_pwd(av, env);
		}
		i++;
	}
	return (av);
}
