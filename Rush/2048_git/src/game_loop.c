/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:12:34 by sduprey           #+#    #+#             */
/*   Updated: 2015/03/01 10:17:36 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

static int	init_curs(int **grid, WINDOW **board, t_coord *max, t_env *e)
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_CYAN);
	init_pair(5, COLOR_WHITE, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(3, COLOR_YELLOW, COLOR_GREEN);
	init_pair(8, COLOR_GREEN, COLOR_RED);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, max->y, max->x);
	max->y -= 3;
	if (draw_grid(board, grid, max, e) == -1)
		return (-1);
	return (0);
}

static char	get_move(int ch)
{
	char move;

	if (ch == 258)
		move = RIGHT;
	else if (ch == 259)
		move = LEFT;
	else if (ch == 260)
		move = UP;
	else if (ch == 261)
		move = DOWN;
	else
		move = NO_MOVE;
	return (move);
}

int			game_loop(WINDOW **board, int **grid, t_env *e)
{
	t_coord max;
	int		ch;
	char	move;

	if (init_curs(grid, board, &max, e) == -1)
		return (0);
	while (42)
	{
		curs_set(0);
		ch = getch();
		if (ch == 27)
			return (end_game(e));
		if (resize_grid(board, grid, e) == -1)
			return (0);
		move = get_move(ch);
		if (move != NO_MOVE)
		{
			resolver(grid, move, e);
			if (resize_grid(board, grid, e) == -1)
				return (0);
		}
	}
	return (0);
}
