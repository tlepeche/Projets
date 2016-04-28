/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 07:09:22 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 09:18:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

int	**cpy_grid(int **grid, t_env *e)
{
	int **cpy;
	int x;
	int y;

	cpy = (int **)malloc(sizeof(int *) * e->gs);
	x = 0;
	while (x < e->gs)
	{
		cpy[x] = (int *)malloc(sizeof(int) * e->gs);
		y = 0;
		while (y < e->gs)
		{
			cpy[x][y] = grid[x][y];
			y++;
		}
		x++;
	}
	return (cpy);
}
