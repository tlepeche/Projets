/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 05:17:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/24 21:03:21 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	test_arg(char **av, char **env, t_restart *r)
{
	if (av[0][ft_strlen(av[0]) - 1] == '/' || av[0][0] == '/')
		test_directory(av, env, r);
	else if (av[0][0] != '.' && av[0][0] != '/')
		exec_bin(av[0], av, env, r);
	if (r->exec == 0 && r->test == 0)
	{
		if (av[0][0] == '.' || av[0][0] == '/')
			test_file(av[0], av, env, r);
		else if (ft_strstr(av[0], "/") != NULL)
			test_command(av[0], r);
		else
		{
			if (r->recurs == 1)
				multi_error("./ft_minishell1: ", av[0], 1, r);
			else
				multi_error("./ft_minishell1: ", av[0], 5, r);
		}
	}
}

char	**analyse_rest(int ac, char **av, char **env, t_restart *r)
{
	if (ft_strcmp(av[0], "cd") == 0)
		env = move_directory(av, env, r);
	else if (ft_strcmp(av[0], "env") == 0)
		env = manage_env(env, ac, av);
	else
		test_arg(av, env, r);
	return (env);
}

char	**analyse_line(int ac, char **av, char **env, t_restart *r)
{
	env = add_last_exec(env, av[0]);
	if (ft_strcmp(av[0], "unsetenv") == 0)
		env = unset_env(env, av, ac);
	else if (ft_strcmp(av[0], "setenv") == 0)
		env = set_env(env, ac, av);
	else if (ft_strcmp(av[0], "exit") == 0)
		r->stop = 1;
	else
		env = analyse_rest(ac, av, env, r);
	return (env);
}

void	signal_handle(void)
{
	///////////REMPLACER SIG_IGN par une fonction sig_handler pour que le	///////
	///////////CTRL+C ... soient pris en compte dans les programmes fils	///////
	//////////ex : ls -r /, le signal est ignore pour le moment				/////////
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

int		main(int ac, char **av, char **env)
{
	char		*line;
	t_restart	res;
	char		**envp;
	int			i;

	(void)av;
	(void)ac;
	signal_handle();
	res.stop = 0;
	envp = init_env(env);
	while (1)
	{
		res.exec = 0;
		res.recurs = 0;
		res.test = 0;
		res.reader = 0;
		display_prompt(envp);
		i = get_next_line(0, &line);
		line = (i == 0) ? ft_strdup("exit") : line;
		envp = init(line, envp, &res);
		free(line);
	}
	return (0);
}
