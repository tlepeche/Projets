/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:52:22 by sduprey           #+#    #+#             */
/*   Updated: 2015/03/01 10:16:00 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

static void	draw_score(t_env *e)
{
	mvwprintw(stdscr, 1, 0, "Score : %d", e->score);
	if (e->score >= e->best)
		mvwprintw(stdscr, 2, 0, "Best  : %d", e->score);
	else
		mvwprintw(stdscr, 2, 0, "Best  : %d", e->best);
}

static void	draw_msg(int max_x, t_env *e)
{
	if (e->check == 1)
		mvwprintw(stdscr, 0, max_x / 2 - 3, "YOU WIN");
	else if (e->check == -1)
		mvwprintw(stdscr, 0, max_x / 2 - 5, "GAME OVER");
}

static int	check_grid_size(t_coord *max, t_env *e)
{
	if (e->gs == 4)
	{
		if (max->y < 12 || max->x < 32)
			return (-1);
	}
	else if (e->gs == 5)
	{
		if (max->y < 15 || max->x < 40)
			return (-1);
	}
	return (0);
}

int			draw_grid(WINDOW **board, int **grid, t_coord *max, t_env *e)
{
	if (check_grid_size(max, e) == -1)
	{
		end_game(e);
		ft_putendl_fd("game_2048: window too small", 2);
		return (-1);
	}
	draw_score(e);
	draw_msg(max->x, e);
	set_window(board, max->x, max->y, e);
	fill_grid(board, grid, e);
	return (0);
}
