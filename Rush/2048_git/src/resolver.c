/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:05:34 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 09:17:03 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static int	check_win(int **grid, t_env *e)
{
	int	x;
	int	y;

	x = 0;
	while (x < e->gs)
	{
		y = 0;
		while (y < e->gs)
		{
			if (grid[x][y] == e->win_value)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	check_full(int **grid, t_env *e)
{
	int	x;
	int	y;

	x = 0;
	while (x < e->gs)
	{
		y = 0;
		while (y < e->gs)
		{
			if (grid[x][y] == 0)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	check_grid(int **grid, t_env *e)
{
	if (check_win(grid, e) == 1)
		return (1);
	if (check_full(grid, e) == 0)
		return (check_move(grid, e));
	else
		return (0);
}

static void	add_number(int **grid, t_env *e)
{
	int	square;
	int	valid;
	int x;
	int	y;

	valid = 0;
	while (valid == 0)
	{
		square = (rand() % (e->gs * e->gs));
		x = square / e->gs;
		y = square % e->gs;
		if (grid[x][y] == 0)
			valid = 1;
	}
	square = (rand() % 100);
	grid[x][y] = square > 80 ? 4 : 2;
}

int			resolver(int **grid, char move, t_env *e)
{
	int check;
	int	**old_grid;

	srand(time(NULL));
	old_grid = cpy_grid(grid, e);
	if (move == UP)
		move_up(grid, e);
	else if (move == DOWN)
		move_down(grid, e);
	else if (move == LEFT)
		move_left(grid, e);
	else
		move_right(grid, e);
	if (check_change(grid, old_grid) == 1)
	{
		add_number(grid, e);
		check = check_grid(grid, e);
		if (check == 1 || check == -1)
			e->check = check;
	}
	free_grid(old_grid, e);
	return (check);
}
