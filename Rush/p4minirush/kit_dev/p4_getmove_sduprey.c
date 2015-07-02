/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_getmove_sduprey.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:22:55 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/03 17:28:37 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"
#include <stdlib.h>
#define WIN 15000

typedef struct	s_weight
{
	int	col;
	int	w;
}				t_weight;

static int		p4_won_hz(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = col;
	while (--i >= 0)
	{
		if ((*grid)[row][i] == color)
			count++;
		else
			break;
	}
	i = col;
	while (++i < GRID_W)
	{
		if ((*grid)[row][i] == color)
			count++;
		else
			break;
	}
	return (count);
}

static int		p4_won_vz(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = row;
	while (--i >= 0)
	{
		if ((*grid)[i][col] == color)
			count++;
		else
			break;
	}
	i = row;
	while (++i < GRID_H)
	{
		if ((*grid)[i][col] == color)
			count++;
		else
			break;
	}
	return (count);
}

static int		p4_won_diag1(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = 1;
	while ((col + i) < GRID_W && (row + i) < GRID_H)
	{
		if ((*grid)[row + i][col + i] == color)
			count++;
		else
			break;
		i++;
	}
	i = -1;
	while ((col + i) >= 0 && (row + i) >= 0)
	{
		if ((*grid)[row + i][col + i] == color)
			count++;
		else
			break;
		i--;
	}
	return (count);
}

static int		p4_won_diag2(t_grid *grid, int col, int row, t_case color)
{
	int		i;
	int		count;

	count = 1;
	i = 1;
	while ((col + i) < GRID_W && (row - i) >= 0)
	{
		if ((*grid)[row - i][col + i] == color)
			count++;
		else
			break;
		i++;
	}
	i = 1;
	while ((col - i) >= 0 && (row + i) < GRID_H)
	{
		if ((*grid)[row + i][col - i] == color)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

static int	p4_location(t_grid *grid, int col)
{
	int	i;

	if (col < 0 || col >= GRID_W)
		return (-1);
	i = GRID_H - 1;
	while (i >= 0)
	{
		if ((*grid)[i][col] == VIDE)
			return (i);
		i--;
	}
	return (-1);
}

int	calc_next_move(t_grid *grid, int col, int row, t_case color, t_case color_us)
{
	t_grid	cpy;
	int i;
	int j;

	i = 0;
	while (i < GRID_H)
	{
		j = 0;
		while (j < GRID_W)
		{
			cpy[i][j] = (*grid)[i][j];
			j++;
		}
		i++;
	}
	(cpy)[row][col] = color_us;
	if (row < 1)
	{
		return (0);
	}
	(cpy)[row - 1][col] = color;
	if (p4_won(&cpy, col) == 1)
		return (1);
	return (0);
}

int	calc_weight(t_grid *grid, int col, int row, t_case color, t_case color_us)
{
	int	weight;
	int	count;

	weight = 0;

	count = p4_won_hz(grid, col, row, color);
	if (count >= WIN_CNT)
		return (color == color_us ? 15000 : 1000);
	else
		weight += count;

	count = p4_won_vz(grid, col, row, color);
//		printf("count vert = %d, row = %d, col = %d\n", count, row, col);
	if (count >= WIN_CNT)
		return (color == color_us ? 15000 : 1000);
	else
		weight += count;

	count = p4_won_diag1(grid, col, row, color);
	if (count >= WIN_CNT)
		return (color == color_us ? 15000 : 1000);
	else
		weight += count;

	count = p4_won_diag2(grid, col, row, color);
	if (count >= WIN_CNT)
		return (color == color_us ? 15000 : 1000);
	else
		weight += count;
	return (weight);
}

int	calc_total_weight(t_grid *grid, int col, int row, t_case color)
{
	int weight;
	int e_color;

	e_color = (color == 1) ? 2 : 1;
	weight = 2;
	weight += calc_weight(grid, col, row, color, color); //calcul poids par rapport a nos jetons
	if (weight >= WIN)
		return (weight); // return direct si on gagne;
	weight += calc_weight(grid, col, row, e_color, color); //calcul poids par rapport a ses jetons
	if (calc_next_move(grid, col, row, e_color, color) == 1) //si prochain coup = gagnant pour ladversaire, ne pas jouer la;
	weight = 1;
	return (weight);	
}

int	p4_getmove_sduprey(t_grid *grid, t_case color, int turn_count)
{
	int	row;
	t_weight prev_weight;
	t_weight weight;
	int	i;

	i = 0;
	weight.w = 0;
	weight.col = 0;
	prev_weight.w = weight.w;
	prev_weight.col = weight.col;
	if (turn_count == 0)
		return (GRID_W / 2);
	while (i < GRID_W)
	{
		row = p4_location(grid, i); // recuperation case ou -1 si col pleine;
		if (row >= 0)
		{
			weight.col = i;
			weight.w = calc_total_weight(grid, i, row, color); // calcul poids;
			if (weight.w > prev_weight.w)
				prev_weight = weight; // verif si col actuelle > col precedente
			if (prev_weight.w == WIN)
				break ;
		}
		i++;
	}
	return (prev_weight.col);
}
