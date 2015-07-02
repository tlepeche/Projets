/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 08:23:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/16 09:37:04 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

static void		update_index(t_arg **arg, int index)
{
	t_arg *tmp;

	tmp = *arg;
	while (tmp != NULL)
	{
		if (tmp->index == index)
		{
			while (tmp != NULL)
			{
				tmp->index -= 1;
				tmp = tmp->next;
			}
			break ;
		}
		tmp = tmp->next;
	}
}

static t_arg	*replace_link(t_win *win, int index)
{
	t_arg *tmp;

	tmp = win->arg;
	while (tmp->next != NULL)
	{
		if (tmp->next->index == index)
		{
			free(tmp->next);
			if (tmp->next->next == NULL)
			{
				tmp->next = NULL;
				break ;
			}
			else
				tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
	return (win->arg);
}

t_arg			*delete_link(t_win *win, int index)
{
	if (index == 0)
	{
		free(win->arg);
		win->arg = win->arg->next;
	}
	else
		win->arg = replace_link(win, index);
	win->i_max = find_imax(win);
	update_index(&(win->arg), index + 1);
	return (win->arg);
}
