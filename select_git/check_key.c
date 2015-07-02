/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 09:42:33 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/02 15:45:36 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

static void	get_new_value(t_win *win, t_wsize *ws)
{
	int start;
	int	space;

	start = 0;
	space = find_space(win->arg);
	win->x = ws->ws_row;
	win->y = ws->ws_col;
	while (space * (start + 1) <= win->y)
		start++;
	win->max_y = start;
	win->i_max = find_imax(win);
}

int			reset_val(t_ios *term, t_wsize *ws, int sig)
{
	t_win	*win;
	int		resize;

	if (ioctl(0, TIOCGWINSZ, ws) == -1)
		leave_term();
	init_term(term);
	win = check_static();
	get_new_value(win, ws);
	resize = check_win(win);
	if (sig == 1)
	{
		clr_screen();
		tputs(tgetstr("vi", NULL), 0, &ft_putterm);
		if (resize == 1)
			print_arg(&(win)->arg, win, win->position, find_space(win->arg));
		else
		{
			if (win->y > 16)
				tputs("Window too small", 1, &ft_putterm);
		}
	}
	return (resize);
}

static void	init_var(t_win *win, int *x, int *y)
{
	int start;

	start = 0;
	while (find_space(win->arg) * (start + 1) <= win->y)
		start++;
	win->max_y = start;
	*x = 0;
	*y = 0;
	win->position = 0;
}

void		print_error(t_win *win, int resize)
{
	char *buf;

	if (resize == 0)
	{
		if (win->stop == 0)
		{
			win->stop = 1;
			clr_screen();
			tputs("Window too small", 1, &ft_putterm);
		}
		else
		{
			buf = ft_memalloc(4);
			read(0, buf, 3);
			if (buf[0] == 27 && !buf[1] && !buf[2])
				leave_term();
			free(buf);
		}
	}
}

void		check_key(t_ios *term, t_win *win, t_wsize *ws)
{
	int		x;
	int		y;
	int		resize;

	clr_screen();
	tputs(tgetstr("vi", NULL), 0, &ft_putterm);
	init_var(win, &x, &y);
	resize = check_win(win);
	if (resize == 1)
		print_arg(&(win->arg), win, 0, find_space(win->arg));
	else
		tputs("Window too small", 1, &ft_putterm);
	while (42)
	{
		if (win->arg == NULL)
			leave_term();
		resize = reset_val(term, ws, 0);
		if (resize == 1)
			move_list(win, term, x, y);
		print_error(win, resize);
	}
}
