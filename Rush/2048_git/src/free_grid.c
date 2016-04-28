/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 06:31:25 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 06:46:54 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

void	free_grid(int **grid, t_env *e)
{
	int	x;

	x = 0;
	while (x < e->gs)
	{
		free(grid[x]);
		grid[x] = NULL;
		x++;
	}
	free(grid);
	grid = NULL;
}
