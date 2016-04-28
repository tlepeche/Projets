/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:51:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 07:14:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static void	move_square(int **grid, int x, int y, t_env *e)
{
	int y_tmp;

	e->move++;
	y_tmp = y;
	while (y_tmp > 0)
	{
		grid[x][y_tmp] = grid[x][y_tmp - 1];
		y_tmp--;
	}
	grid[x][0] = 0;
}

static void	grid_move(int **grid, t_env *e)
{
	int	x;
	int	y;

	x = 0;
	while (x < e->gs)
	{
		y = e->gs - 1;
		while (y > 0)
		{
			if (grid[x][y] == 0 && e->move <= 3)
				move_square(grid, x, y, e);
			else
			{
				e->move = 0;
				y--;
			}
		}
		e->move = 0;
		x++;
	}
}

static void	merge_grid(int **grid, t_env *e)
{
	int	x;
	int	y;

	x = 0;
	while (x < e->gs)
	{
		y = e->gs - 1;
		while (y > 0)
		{
			if (grid[x][y] == grid[x][y - 1])
			{
				grid[x][y] *= 2;
				e->score += grid[x][y];
				grid[x][y - 1] = 0;
			}
			y--;
		}
		x++;
	}
}

void		move_right(int **grid, t_env *e)
{
	e->move = 0;
	grid_move(grid, e);
	merge_grid(grid, e);
	e->move = 0;
	grid_move(grid, e);
}
