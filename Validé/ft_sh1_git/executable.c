/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 08:28:43 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/05 01:50:55 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*get_file(char *dir, char *file)
{
	char	*str;

	str = ft_strjoin(dir, "/");
	free(str);
	str = ft_strjoin(str, file);
	return (str);
}

void	free_memory(char ***path, int i)
{
	while (path[0][i])
	{
		free(path[0][i]);
		i++;
	}
	free(*path);
}

void	free_remain(t_stat **stat, char ***path)
{
	free(*stat);
	free(*path);
}

void	exec(char **av, char **env, char *str, t_restart *r)
{
	pid_t			father;
	t_stat			*f_stat;

	f_stat = (t_stat *)malloc(sizeof(t_stat));
	if (stat(str, f_stat) == 0)
		r->exec = 1;
	father = fork();
	if (father > 0)
		waitpid(father, 0, 0);
	if (father == 0)
	{
		if (execve(str, av, env) == -1)
			exit (0);
	}
	free(f_stat);
}

void	exec_bin(char *exe, char **av, char **env, t_restart *r)
{
	int				i;
	char			*str;
	char			**path;

	r->exec = 0;
	path = get_path(env);
	av = change_av(av, env);
	i = 0;
	while (path[i])
	{
		str = get_file(path[i], exe);
		exec(av, env, str, r);
		if (r->exec == 1)
			break ;
		free(path[i]);
		free(str);
		i++;
	}
	if (r->exec == 1)
		free(str);
	free_memory(&path, i);
}
