/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 23:14:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 09:29:42 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static void	choose_command_next(char *cmd, t_env *e)
{
	int fd;

	if (ft_strcmp(cmd, "2\n") == 0)
	{
		fd = open("score.txt", O_RDONLY);
		if (fd == -1)
			ft_putendl("No High Score");
		else
		{
			read(fd, cmd, 1024);
			if (ft_strcmp(cmd, "2\n") == 0)
				ft_putendl("No High Score");
			else
			{
				ft_putstr("High Score = ");
				ft_putendl(cmd);
			}
		}
		sleep(3);
		launch(e);
	}
	exit(0);
}

static void	choose_command(char *cmd, t_env *e)
{
	int		size;
	int		**grid;
	WINDOW	**board;

	if (ft_strcmp(cmd, "1\n") == 0)
	{
		size = (e->gs * e->gs);
		board = (WINDOW **)malloc(sizeof(WINDOW *) * size);
		if (board == NULL)
			exit(0);
		srand(time(NULL));
		grid = init_grid(e);
		game_loop(board, grid, e);
		free(cmd);
	}
	else if (ft_strcmp(cmd, "3\n") == 0)
	{
		free(cmd);
		option(e);
	}
	else
		choose_command_next(cmd, e);
}

static void	print_start(void)
{
	system("clear");
	ft_putendl("#############################");
	ft_putendl("#      Welcome to 2048      #");
	ft_putendl("#                           #");
	ft_putendl("# 1: New Game               #");
}

void		launch(t_env *e)
{
	char	*cmd;
	int		ret;
	int		cmd_valid;

	cmd_valid = 0;
	cmd = (char *)malloc(sizeof(char) * 1024);
	while (cmd_valid == 0)
	{
		print_start();
		ft_putendl("# 2: High Score             #");
		ft_putendl("# 3: Options                #");
		ft_putendl("# 4: Exit                   #");
		ft_putendl("#         By: Team Squalala #");
		ft_putendl("#############################");
		ret = read(0, cmd, 1024);
		cmd[ret] = '\0';
		if (ft_strcmp(cmd, "1\n") == 0 || ft_strcmp(cmd, "2\n") == 0 ||
				ft_strcmp(cmd, "3\n") == 0 || ft_strcmp(cmd, "4\n") == 0)
			cmd_valid = 1;
	}
	choose_command(cmd, e);
}
