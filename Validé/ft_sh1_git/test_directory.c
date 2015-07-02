/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 06:31:07 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 09:39:14 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		check_stat(int mode)
{
	if ((mode > S_IFBLK) == 1)
		return (0);
	else if ((mode > S_IFSOCK) == 1)
		return (0);
	else if ((mode > S_IFREG) == 1)
		return (0);
	return (1);
}

char	*complete_dir(char *dir, char *str)
{
	char	*tmp_av;

	tmp_av = ft_strsub(str, 2, ft_strlen(str));
	free(dir);
	dir = ft_strjoin(dir, tmp_av);
	free(tmp_av);
	return (dir);
}

void	multi_error(char *exec, char *file, int er, t_restart *r)
{
	if (r->reader == 1)
	{
		ft_putstr_fd(r->file, 2);
		ft_putstr_fd(": line ", 2);
		ft_putnbr_fd(r->line, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(exec, 2);
	ft_putstr_fd(file, 2);
	if (er == 1)
		ft_putendl_fd(": No such file or directory", 2);
	else if (er == 2)
		ft_putendl_fd(": Permission denied", 2);
	else if (er == 3)
		ft_putendl_fd(": Not a directory", 2);
	else if (er == 4)
		ft_putendl_fd(": is a directory", 2);
	else if (er == 5)
		ft_putendl_fd(": command not found", 2);
}

void	to_dir_or_not_to_dir(char *f_name, char **av, t_restart *r)
{
	t_stat	*f_stat;

	f_stat = (t_stat *)malloc(sizeof(t_stat));
	stat(f_name, f_stat);
	if (check_stat(f_stat->st_mode) == 1)
		multi_error("./ft_minishell1: ", av[0], 4, r);
	else
		multi_error("./ft_minishell1: ", av[0], 3, r);
	free(f_stat);
}

void	test_directory(char **av, char **env, t_restart *r)
{
	char	*f_name;

	r->test = 1;
	if (av[0][ft_strlen(av[0]) - 1] == '/' && ft_strlen(av[0]) != 1)
		f_name = ft_strsub(av[0], 0, ft_strlen(av[0]) - 1);
	else
		f_name = ft_strdup(av[0]);
	if (access(f_name, F_OK) != -1)
	{
		if (av[0][ft_strlen(av[0]) - 1] == '/')
			to_dir_or_not_to_dir(f_name, av, r);
		else
			r->exec = test_exec(av[0], av, env, r);
	}
	else
		multi_error("./ft_minishell1: ", av[0], 1, r);
	free(f_name);
}
