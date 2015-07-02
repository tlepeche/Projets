/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 07:59:57 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/02 15:49:52 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

static void	selection(t_arg *arg, int index, int *select)
{
	*select = 1;
	while (arg != NULL)
	{
		if (arg->index == index)
			arg->select = (arg->select + 1) % 2;
		arg = arg->next;
	}
}

static int	check_buf(char *buf, t_win *win, int position, t_ios *term)
{
	int select;

	select = 0;
	if (buf[0] == 32)
		selection(win->arg, position, &select);
	else if (buf[0] == 4)
	{
		if (tcsetattr(0, TCSADRAIN, term) == -1)
			leave_term();
	}
	else if (buf[0] == 10)
		print_selected(win->arg);
	else if (buf[0] == 114)
		select_reverse(win->arg);
	else if (buf[0] == 97)
		select_all(win->arg);
	else if ((buf[0] == 126 || buf[0] == 127))
	{
		clr_screen();
		win->arg = delete_link(win, position);
	}
	return (select);
}

static void	get_position(t_win *win, int select, int *x, int *y)
{
	win->position = *y * win->max_y + *x;
	win->position += select == 1 ? 1 : 0;
	win->position = win->position == win->i_max ? 0 : win->position;
	*y = win->position / win->max_y;
	*x = win->position % win->max_y;
}

int			check_win(t_win *win)
{
	int		nb_line;

	if (win->max_y == 0)
		return (0);
	nb_line = win->i_max / win->max_y + 1;
	if (nb_line > win->x)
		return (0);
	return (1);
}

void		move_list(t_win *win, t_ios *term, int x, int y)
{
	char	*buf;
	int		select;
	t_wsize	ws;
	int		resize;

	if (tcsetattr(0, TCSADRAIN, term) == -1)
		leave_term();
	buf = ft_memalloc(5);
	win->stop = 0;
	read(0, buf, 3);
	resize = reset_val(term, &ws, 0);
	if (resize != 0)
	{
		y = win->position / win->max_y;
		x = win->position % win->max_y;
		check_move(buf, &y, &x, win);
		select = check_buf(buf, win, win->position, term);
		get_position(win, select, &x, &y);
		print_arg(&(win->arg), win, win->position, find_space(win->arg));
	}
	free(buf);
}
