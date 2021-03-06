/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:16:03 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 07:14:07 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static void	move_square(int **grid, int x, int y, t_env *e)
{
	int	x_tmp;

	e->move++;
	x_tmp = x;
	while (x_tmp > 0)
	{
		grid[x_tmp][y] = grid[x_tmp - 1][y];
		x_tmp--;
	}
	grid[0][y] = 0;
}

static void	grid_move(int **grid, t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->gs)
	{
		x = e->gs - 1;
		while (x > 0)
		{
			if (grid[x][y] == 0 && e->move <= 3)
				move_square(grid, x, y, e);
			else
			{
				e->move = 0;
				x--;
			}
		}
		e->move = 0;
		y++;
	}
}

static void	merge_grid(int **grid, t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->gs)
	{
		x = e->gs - 1;
		while (x > 0)
		{
			if (grid[x][y] == grid[x - 1][y])
			{
				grid[x][y] *= 2;
				e->score += grid[x][y];
				grid[x - 1][y] = 0;
			}
			x--;
		}
		y++;
	}
}

void		move_down(int **grid, t_env *e)
{
	e->move = 0;
	grid_move(grid, e);
	merge_grid(grid, e);
	e->move = 0;
	grid_move(grid, e);
}
