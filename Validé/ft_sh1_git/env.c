/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 21:23:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 09:35:26 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		manage_new_env(char **av, char ***new_env, int i)
{
	char		**new_av;
	int			new_ac;
	t_restart	r;

	if (av[i][0] == '=')
	{
		ft_putendl_fd("env: Error: can't switch shell", 2);
		return (1);
	}
	if (how_many(av[i], '=') != 0)
	{
		*new_env = add_var_env(*new_env, av[i]);
		if (i == ft_tablen(av) - 1)
			ft_printtab(*new_env);
	}
	else
	{
		new_ac = ft_tablen(av) - i;
		new_av = create_nav(av, new_ac, i, &r);
		r.recurs = 1;
		*new_env = analyse_line(new_ac, new_av, *new_env, &r);
		free_tab(new_av);
		return (1);
	}
	return (0);
}

int		check_option_env(char **av, char ***new_env, int i)
{
	int		j;

	j = 1;
	if (av[i][0] == '-')
	{
		while (av[i][j] && (av[i][j] == '-' || av[i][j] == 'i'))
		{
			if (av[i][j] == '-')
				*new_env = destroy_env(*new_env);
			j++;
		}
		if (av[i][j] && av[i][j] != '-' && av[i][j] != 'i')
		{
			ft_putstr("env: illegal option -- ");
			ft_putchar(av[i][j]);
			ft_putendl("\nusage: env [-i] [name=value ...] \
[utility [argument ...]]");
			return (0);
		}
	}
	else
		return (0);
	return (1);
}

int		check_arg_env(char **av, char ***new_env, int i, int *arg)
{
	if (av[i][0] != '-')
		*arg = 1;
	if (*arg == 0)
	{
		if (check_option_env(av, new_env, i) == 0)
			return (0);
	}
	else
	{
		if (manage_new_env(av, new_env, i) == 1)
			return (0);
	}
	return (1);
}

void	modify_env(int ac, char **av, char **env)
{
	int		i;
	char	**new_env;
	int		arg;

	i = 1;
	arg = 0;
	new_env = cpy(env);
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-i") == 0)
		{
			i++;
			if (av[i])
				new_env = destroy_env(new_env);
		}
		else
			break ;
	}
	while (i < ac)
	{
		if (check_arg_env(av, &new_env, i, &arg) == 0)
			break ;
		i++;
	}
	free_tab(new_env);
}

char	**manage_env(char **env, int ac, char **av)
{
	if (ac != 1)
		modify_env(ac, av, env);
	else
		ft_printtab(env);
	return (env);
}
