/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_getmove_nalcaraz.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klonger <klonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:32:46 by klonger           #+#    #+#             */
/*   Updated: 2015/02/03 16:32:49 by klonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"
#include <stdio.h>
#include <stdlib.h>

int		p4_getmove_nalcaraz(t_grid *grid, t_case color, int turn_count)
{
	int					move;
	int					x;
	unsigned int		ennemy;
	int					y;
	int					temp;

	move = 0;
	if (color == ROUGE)
		ennemy = JAUNE;
	if (color == JAUNE)
		ennemy = ROUGE;
	(void)turn_count;
	y = GRID_H;
	move = 0;
/*ATTACK */

	while (y > 0)
	{
		x = 0;
		while (x < GRID_W)
		{
			temp = y;
			while (temp > 0)
			{
				if ((*grid)[y][x] == color)
					move = x;
/*H +*/			if ((*grid)[y][x] == color && (*grid)[y][x + 1] == color && (*grid)[y][x + 2] == color && (*grid)[y][x + 3] == VIDE && (x + 3 < GRID_W))
				{
					move = x + 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y][x + 1] == color && (*grid)[y][x + 2] == color && (*grid)[y][x + 3] == color && (x + 3 < GRID_W))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y][x + 1] == VIDE && (*grid)[y][x + 2] == color && (*grid)[y][x + 3] == color && (x + 3 < GRID_W))
				{
					move = x + 1;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y][x + 1] == color && (*grid)[y][x + 2] == VIDE && (*grid)[y][x + 3] == color && (x + 3 < GRID_W))
				{
					move = x + 2;
					return (move);
				}

/*H - */		else if ((*grid)[y][x] == color && (*grid)[y][x - 1] == color && (*grid)[y][x - 2] == color && (*grid)[y][x - 3] == VIDE && (x - 3 > 0))
				{
					move = x - 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y][x - 1] == color && (*grid)[y][x - 2] == color && (*grid)[y][x - 3] == color && (x - 3 > 0))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y][x - 1] == VIDE && (*grid)[y][x - 2] == color && (*grid)[y][x - 3] == color && (x - 3 > 0))
				{
					move = x - 2;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y][x - 1] == color && (*grid)[y][x - 2] == VIDE && (*grid)[y][x - 3] == color && (x - 3 > 0))
				{
					move = x - 1;
					return (move);
				}

/*V + */		else if ((*grid)[y][x] == color && (*grid)[y + 1][x] == color && (*grid)[y + 2][x] == color && (*grid)[y + 3][x] == VIDE && (y + 3 < GRID_H))
				{
					move = x;
					return (move);
				}

/*V - */		else if ((*grid)[y][x] == color && (*grid)[y - 1][x] == color && (*grid)[y - 2][x] == color && (*grid)[y - 3][x] == VIDE && (y - 3 > 0))
				{
					move = x;
					return (move);
				}
/* D ->BHD */	else if ((*grid)[y][x] == color && (*grid)[y - 1][x + 1] == color && (*grid)[y - 2][x + 2] == color && (*grid)[y - 3][x + 3] == VIDE && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x + 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y - 1][x + 1] == color && (*grid)[y - 2][x + 2] == color && (*grid)[y - 3][x + 3] == color && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y - 1][x + 1] == VIDE && (*grid)[y - 2][x + 2] == color && (*grid)[y - 3][x + 3] == color && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x + 1;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y - 1][x + 1] == color && (*grid)[y - 2][x + 2] == VIDE && (*grid)[y - 3][x + 3] == color && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x + 2;
					return (move);
				}
/* D ->BHG */	else if ((*grid)[y][x] == color && (*grid)[y - 1][x - 1] == color && (*grid)[y - 2][x - 2] == color && (*grid)[y - 3][x - 3] == VIDE && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x - 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y - 1][x - 1] == color && (*grid)[y - 2][x - 2] == color && (*grid)[y - 3][x - 3] == color && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y - 1][x - 1] == VIDE && (*grid)[y - 2][x - 2] == color && (*grid)[y - 3][x - 3] == color && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x - 1;
					return (move);
				}
				else if ((*grid)[y][x] == color && (*grid)[y - 1][x - 1] == color && (*grid)[y - 2][x - 2] == VIDE && (*grid)[y - 3][x - 3] == color && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x - 2;
					return (move);
				}
				temp--;
			}
			x++;
		}
		y--;
	}

/* DEFENSE */
	y = GRID_H;
	move = 0;
	while (y > 0)
	{
		x = 0;
		while (x < GRID_W)
		{
			temp = y;
			while (temp > 0)
			{
				if ((*grid)[y][x] == ennemy)
					move = x;
/*H +*/			if ((*grid)[y][x] == ennemy && (*grid)[y][x + 1] == ennemy && (*grid)[y][x + 2] == ennemy && (*grid)[y][x + 3] == VIDE && (x + 3 < GRID_W))
				{
					move = x + 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y][x + 1] == ennemy && (*grid)[y][x + 2] == ennemy && (*grid)[y][x + 3] == ennemy && (x + 3 < GRID_W))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y][x + 1] == VIDE && (*grid)[y][x + 2] == ennemy && (*grid)[y][x + 3] == ennemy && (x + 3 < GRID_W))
				{
					move = x + 1;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y][x + 1] == ennemy && (*grid)[y][x + 2] == VIDE && (*grid)[y][x + 3] == ennemy && (x + 3 < GRID_W))
				{
					move = x + 2;
					return (move);
				}

/*H - */		else if ((*grid)[y][x] == ennemy && (*grid)[y][x - 1] == ennemy && (*grid)[y][x - 2] == ennemy && (*grid)[y][x - 3] == VIDE && (x - 3 > 0))
				{
					move = x - 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y][x - 1] == ennemy && (*grid)[y][x - 2] == ennemy && (*grid)[y][x - 3] == ennemy && (x - 3 > 0))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y][x - 1] == VIDE && (*grid)[y][x - 2] == ennemy && (*grid)[y][x - 3] == ennemy && (x - 3 > 0))
				{
					move = x - 2;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y][x - 1] == ennemy && (*grid)[y][x - 2] == VIDE && (*grid)[y][x - 3] == ennemy && (x - 3 > 0))
				{
					move = x - 1;
					return (move);
				}

/*V + */		else if ((*grid)[y][x] == ennemy && (*grid)[y + 1][x] == ennemy && (*grid)[y + 2][x] == ennemy && (*grid)[y + 3][x] == VIDE && (y + 3 < GRID_H))
				{
					move = x;
					return (move);
				}

/*V - */		else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x] == ennemy && (*grid)[y - 2][x] == ennemy && (*grid)[y - 3][x] == VIDE && (y - 3 > 0))
				{
					move = x;
					return (move);
				}
/* D ->BHD */	else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x + 1] == ennemy && (*grid)[y - 2][x + 2] == ennemy && (*grid)[y - 3][x + 3] == VIDE && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x + 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y - 1][x + 1] == ennemy && (*grid)[y - 2][x + 2] == ennemy && (*grid)[y - 3][x + 3] == ennemy && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x + 1] == VIDE && (*grid)[y - 2][x + 2] == ennemy && (*grid)[y - 3][x + 3] == ennemy && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x + 1;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x + 1] == ennemy && (*grid)[y - 2][x + 2] == VIDE && (*grid)[y - 3][x + 3] == ennemy && (*grid)[y - 2][x + 3] != VIDE && (y - 3 > 0) && (x + 3 < GRID_W))
				{
					move = x + 2;
					return (move);
				}
/* D ->BHG */	else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x - 1] == ennemy && (*grid)[y - 2][x - 2] == ennemy && (*grid)[y - 3][x - 3] == VIDE && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x - 3;
					return (move);
				}
				else if ((*grid)[y][x] == VIDE && (*grid)[y - 1][x - 1] == ennemy && (*grid)[y - 2][x - 2] == ennemy && (*grid)[y - 3][x - 3] == ennemy && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x - 1] == VIDE && (*grid)[y - 2][x - 2] == ennemy && (*grid)[y - 3][x - 3] == ennemy && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x - 1;
					return (move);
				}
				else if ((*grid)[y][x] == ennemy && (*grid)[y - 1][x - 1] == ennemy && (*grid)[y - 2][x - 2] == VIDE && (*grid)[y - 3][x - 3] == ennemy && (*grid)[y - 2][x - 3] != VIDE && (y - 3 > 0) && (x - 3 > 0))
				{
					move = x - 2;
					return (move);
				}
				temp--;
			}
			x++;
		}
		y--;
	}
	while (p4_legal(grid, move) == 0)
	{
		move = rand();
		move = move % 10;
		if (move > GRID_W)
			move = GRID_W;
	}

	return (move);
}
