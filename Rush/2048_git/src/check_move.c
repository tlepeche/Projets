/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:07:30 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 07:15:03 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static int	compare_square(int **grid, int x, int y, t_env *e)
{
	if (y == (e->gs - 1) && x == (e->gs - 1))
		return (-1);
	else if (y == e->gs - 1)
	{
		if (grid[x][y] == grid[x + 1][y])
			return (0);
	}
	else if (x == e->gs - 1)
	{
		if (grid[x][y] == grid[x][y + 1])
			return (0);
	}
	else
	{
		if (grid[x][y] == grid[x + 1][y] ||
				grid[x][y] == grid[x][y + 1])
			return (0);
	}
	return (1);
}

int			check_move(int **grid, t_env *e)
{
	int	x;
	int	y;

	x = 0;
	while (x < e->gs)
	{
		y = 0;
		while (y < e->gs)
		{
			if (compare_square(grid, x, y, e) == 0)
				return (0);
			else if (compare_square(grid, x, y, e) == -1)
				break ;
			y++;
		}
		x++;
	}
	return (-1);
}
