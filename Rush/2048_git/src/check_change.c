/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 07:15:53 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/28 22:02:30 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

int		check_change(int **grid, int **old_grid)
{
	int x;
	int y;

	x = 0;
	while (x < GRID_SIZE)
	{
		y = 0;
		while (y < GRID_SIZE)
		{
			if (grid[x][y] != old_grid[x][y])
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
