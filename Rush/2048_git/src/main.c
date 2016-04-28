/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:40:50 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 10:37:09 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static int	error_env(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_putendl_fd("game_2048 : Environment uninitialized", 2);
	return (0);
}

void		init_env(t_env *e)
{
	char	*cmd;
	int		fd;

	cmd = (char *)malloc(sizeof(char) * 1024);
	e->win_value = WIN_VALUE;
	e->gs = GRID_SIZE;
	e->score = 0;
	e->check = 0;
	fd = open("score.txt", O_RDONLY);
	if (fd == -1)
		e->best = 0;
	else
	{
		read(fd, cmd, 1024);
		if (ft_strcmp(cmd, "\n") == 0)
			e->best = 0;
		else
			e->best = ft_atoi(cmd);
	}
}

int			main(int ac, char **av, char **env)
{
	t_env	e;

	if (env[0] == NULL)
		return (error_env(ac, av));
	if ((GRID_SIZE != 4 && GRID_SIZE != 5) || check_power(WIN_VALUE) == 0)
		return (0);
	init_env(&e);
	launch(&e);
	return (0);
}
