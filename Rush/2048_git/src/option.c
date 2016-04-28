/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 06:41:15 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 09:40:26 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static void		print_grid_choice(t_env *e)
{
	if (e->gs == 4)
	{
		ft_putstr("\033[32m");
		ft_putstr("4");
		ft_putstr("\033[0m");
		ft_putstr(" / 5");
	}
	else
	{
		ft_putstr("4 / ");
		ft_putstr("\033[32m");
		ft_putstr("5");
		ft_putstr("\033[0m");
	}
}

static void		choose_command(char *cmd, t_env *e)
{
	int		new_wv;
	int		ret;

	if (ft_strcmp(cmd, "1\n") == 0)
	{
		ft_putendl("Write new value");
		ret = read(0, cmd, 1024);
		cmd[ret] = '\0';
		new_wv = ft_atoi(cmd);
		if (new_wv <= 8 || check_power(new_wv) == 0)
		{
			ft_putendl_fd("Invalid value", 2);
			sleep(3);
		}
		else
			e->win_value = new_wv;
	}
	else if (ft_strcmp(cmd, "2\n") == 0)
		e->gs = e->gs == 4 ? 5 : 4;
	else
	{
		launch(e);
		exit (0);
	}
	option(e);
}

static void		print_start(t_env *e)
{
	char *str;

	system("clear");
	ft_putendl("#############################");
	ft_putendl("#      Welcome to 2048      #");
	ft_putendl("#                           #");
	ft_putstr("# 1: Win Value = ");
	str = ft_itoa(e->win_value);
	ft_putstr(str);
	ft_putspace(11 - ft_strlen(str));
	free(str);
	ft_putendl("#");
}

void			option(t_env *e)
{
	char	*cmd;
	int		ret;
	int		cmd_valid;

	cmd_valid = 0;
	while (cmd_valid == 0)
	{
		print_start(e);
		ft_putstr("# 2: Grid Size = ");
		print_grid_choice(e);
		ft_putendl("      #");
		ft_putendl("# 3: Return                 #");
		ft_putendl("#         By: Team Squalala #");
		ft_putendl("#############################");
		cmd = (char *)malloc(sizeof(char) * 24);
		ret = read(0, cmd, 24);
		cmd[ret] = '\0';
		if (ft_strcmp(cmd, "1\n") == 0 || ft_strcmp(cmd, "2\n") == 0 ||
				ft_strcmp(cmd, "3\n") == 0)
			cmd_valid = 1;
		else
			free(cmd);
	}
	choose_command(cmd, e);
}
