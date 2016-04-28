/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:00:38 by sduprey           #+#    #+#             */
/*   Updated: 2015/03/01 07:49:01 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

int	resize_grid(WINDOW **board, int **grid, t_env *e)
{
	t_coord max;
	int		x;
	int		y;

	endwin();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	getmaxyx(stdscr, y, x);
	max.x = x;
	max.y = y - 3;
	clear();
	if (draw_grid(board, grid, &max, e) == -1)
		return (-1);
	return (0);
}
