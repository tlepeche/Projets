/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:38:24 by sduprey           #+#    #+#             */
/*   Updated: 2015/03/01 09:49:33 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

static int	slct_color(int nb)
{
	int color;

	if (nb == 0)
		color = 2;
	else if (nb == 2 || nb == 4)
		color = 3;
	else if (nb == 8 || nb == 16)
		color = 4;
	else if (nb == 32 || nb == 64)
		color = 5;
	else if (nb == 128 || nb == 256)
		color = 6;
	else if (nb == 512 || nb == 1024)
		color = 7;
	else
		color = 8;
	return (color);
}

static void	set_box_color(WINDOW *bcase)
{
	wattron(bcase, COLOR_PAIR(1));
	box(bcase, 0, 0);
	wattroff(bcase, COLOR_PAIR(2));
}

static int	set_alignment(int nb)
{
	int	align;

	align = 0;
	if (nb >= 10)
		align = -1;
	else if (nb >= 1000)
		align = -3;
	else if (nb >= 100000)
		align = -5;
	return (align);
}

static void	fill_case(WINDOW *bcase, int nb)
{
	int x;
	int y;
	int	max_x;
	int	max_y;
	int	color;

	color = slct_color(nb);
	getmaxyx(bcase, max_y, max_x);
	wattron(bcase, A_BOLD);
	wattron(bcase, COLOR_PAIR(color));
	y = 0;
	while (y < max_y)
	{
		x = -1;
		while (x++ < max_x)
			mvwprintw(bcase, y, x, " ");
		y++;
	}
	if (nb != 0)
		mvwprintw(bcase, max_y / 2, max_x / 2 + set_alignment(nb), "%d", nb);
	wattroff(bcase, COLOR_PAIR(color));
	wattroff(bcase, A_BOLD);
	set_box_color(bcase);
}

void		fill_grid(WINDOW **board, int **grid, t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->gs)
	{
		x = 0;
		while (x < e->gs)
		{
			fill_case(board[y * e->gs + x], grid[x][y]);
			x++;
		}
		y++;
	}
}
