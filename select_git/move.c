/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 06:16:06 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/02 15:40:09 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

static void	move_up(char c, int *y, int *x, t_win *win)
{
	if (c == 65)
	{
		if ((*y) == 0)
		{
			if ((*x) == 0)
				*x = win->max_y - 1;
			else
				*x -= 1;
			*y = win->i_max / win->max_y;
			if (*y * win->max_y + *x >= win->i_max)
				*y -= 1;
		}
		else
			*y -= 1;
	}
}

static void	move_down(char c, int *y, int *x, t_win *win)
{
	if (c == 66)
	{
		if (((*y) + 1) * win->max_y + (*x) >= win->i_max)
		{
			*y = 0;
			if (*x == win->max_y - 1)
				*x = 0;
			else
				*x += 1;
		}
		else
			*y += 1;
	}
}

static void	move_right(char c, int *y, int *x, t_win *win)
{
	if (c == 67)
	{
		*x += 1;
		if (*y * win->max_y + *x == win->i_max)
		{
			*x = 0;
			*y = 0;
		}
	}
}

static void	move_left(char c, int *y, int *x, t_win *win)
{
	if (c == 68)
	{
		if (*x == 0 && *y == 0)
		{
			*x = win->i_max % win->max_y - 1;
			*y = win->i_max / win->max_y;
		}
		else
			*x -= 1;
	}
}

void		check_move(char *buf, int *y, int *x, t_win *win)
{
	if (buf[0] == 27)
	{
		move_up(buf[2], y, x, win);
		move_down(buf[2], y, x, win);
		move_left(buf[2], y, x, win);
		move_right(buf[2], y, x, win);
		if (!buf[1] && !buf[2])
			leave_term();
	}
}
