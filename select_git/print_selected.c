/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_selected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 07:31:42 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/09 19:10:12 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

void		select_all(t_arg *arg)
{
	t_arg		*tmp;
	static int	a;

	tmp = arg;
	a = a == 0 ? 1 : 0;
	while (tmp != NULL)
	{
		if (a == 1)
			tmp->select = 1;
		else
			tmp->select = 0;
		tmp = tmp->next;
	}
}

void		select_reverse(t_arg *arg)
{
	t_arg	*tmp;

	tmp = arg;
	while (tmp != NULL)
	{
		tmp->select = (tmp->select + 1) % 2;
		tmp = tmp->next;
	}
}

void		leave_term(void)
{
	char	*str;
	t_win	*win;

	win = check_static();
	str = tgetstr("ve", NULL);
	tputs(str, 1, &ft_putterm);
	str = tgetstr("te", NULL);
	tputs(str, 1, &ft_putterm);
	tcsetattr(0, 0, &(win->ori_term));
	exit(0);
}

void		print_selected(t_arg *arg)
{
	int		first;
	char	*str;

	clr_screen();
	str = tgetstr("te", NULL);
	tputs(str, 1, &ft_putterm);
	first = 0;
	while (arg != NULL)
	{
		if (arg->select == 1)
		{
			if (first == 0)
				first = 1;
			else
				ft_putchar(' ');
			ft_putstr(arg->path);
		}
		arg = arg->next;
	}
	str = tgetstr("ve", NULL);
	tputs(str, 1, &ft_putterm);
	exit(0);
}
