/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 19:34:14 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/22 02:37:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	init_new_r(t_restart *r)
{
	r->stop = 0;
	r->exec = 0;
	r->recurs = 0;
	r->test = 0;
	r->line = 0;
	r->reader = 1;
}

void	read_file(char *exe, char **env)
{
	int			fd;
	char		*line;
	char		**tmp_env;
	t_restart	r;

	init_new_r(&r);
	fd = open(exe, O_RDONLY);
	if (fd == -1)
		return ;
	r.file = ft_strdup(exe);
	tmp_env = init_env(env);
	while (get_next_line(fd, &line) > 0)
	{
		r.line++;
		tmp_env = init(line, tmp_env, &r);
	}
	free_tab(env);
	if (r.line != 0)
		free(line);
	free(r.file);
	close(fd);
}

void	exec_file(char *exe, char **av, char **env)
{
	pid_t		father;

	father = fork();
	if (father > 0)
		waitpid(father, 0, 0);
	if (father == 0)
	{
		if (execve(exe, av, env) == -1)
		{
			read_file(exe, env);
			exit(0);
		}
	}
}

int		test_exec(char *exe, char **av, char **env, t_restart *r)
{
	DIR		*dir;
	char	*file;

	if (exe[0] == '.')
		file = ft_strsub(exe, 2, ft_strlen(exe));
	else
		file = ft_strdup(exe);
	if ((dir = opendir(file)) != NULL)
	{
		multi_error("./ft_minishell1: ", file, 4, r);
		closedir(dir);
	}
	else
	{
		if (access(file, X_OK) != -1)
		{
			exec_file(exe, av, env);
			free(file);
			return (1);
		}
		else
			multi_error("./ft_minishell1: ", exe, 2, r);
	}
	free(file);
	return (0);
}

void	test_file(char *exe, char **av, char **env, t_restart *r)
{
	char	*file;

	if (exe[0] == '.')
		file = ft_strsub(exe, 2, ft_strlen(exe));
	else
		file = ft_strdup(exe);
	if (access(file, F_OK) == -1)
		multi_error("./ft_minishell1: ", exe, 1, r);
	else
		test_exec(exe, av, env, r);
	free(file);
}
