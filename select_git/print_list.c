/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 00:33:07 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 03:02:47 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

int			find_space(t_arg *av)
{
	t_arg	*tmp;
	int		space;

	tmp = av;
	space = 24;
	while (tmp != NULL)
	{
		if (tmp->len > space - 1)
			space = ((tmp->len / 8) + 1) * 8;
		tmp = tmp->next;
	}
	return (space);
}

static void	print_n_cancel(t_arg *tmp, int i, int j)
{
	char	*ss_lgn;
	char	*sr_lgn;

	tputs(tmp->str, 1, &ft_putterm);
	ss_lgn = tgetstr("ue", NULL);
	sr_lgn = tgetstr("me", NULL);
	tputs(tgoto(sr_lgn, i, j), 1, &ft_putterm);
	tputs(tgoto(ss_lgn, i, j), 1, &ft_putterm);
}

static void	change_line(int space, int *i, int *j, t_win *win)
{
	if (space * (*i + 1) > win->y)
	{
		*i = 0;
		*j += 1;
	}
}

static void	srl_print(t_arg *tmp, int i, int j)
{
	char	*sr_lgn;

	if (tmp->select == 1)
	{
		sr_lgn = tgetstr("mr", NULL);
		tputs(tgoto(sr_lgn, i, j), 1, &ft_putterm);
	}
}

void		print_arg(t_arg **av, t_win *win, int position, int space)
{
	char	*str;
	char	*ss_lgn;
	int		i;
	int		j;
	t_arg	*tmp;

	tmp = *av;
	i = 0;
	j = 0;
	tputs(tgetstr("vi", NULL), 0, &ft_putterm);
	str = tgetstr("cm", NULL);
	while (tmp != NULL)
	{
		change_line(space, &i, &j, win);
		tputs(tgoto(str, space * i, j), 1, &ft_putterm);
		srl_print(tmp, space * i, j);
		if (j * win->max_y + i == position)
		{
			ss_lgn = tgetstr("us", NULL);
			tputs(tgoto(ss_lgn, space * i, j), 1, &ft_putterm);
		}
		print_n_cancel(tmp, space * i, j);
		tmp = tmp->next;
		i++;
	}
}
