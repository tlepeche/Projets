/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 06:52:06 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 06:52:50 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

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

int			**init_grid(t_env *e)
{
	int	**grid;
	int x;
	int	y;

	grid = (int **)malloc(sizeof(int *) * e->gs);
	x = 0;
	while (x < e->gs)
	{
		grid[x] = (int *)malloc(sizeof(int) * e->gs);
		x++;
	}
	x = 0;
	while (x < e->gs)
	{
		y = 0;
		while (y < e->gs)
		{
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
	add_number(grid, e);
	add_number(grid, e);
	return (grid);
}
