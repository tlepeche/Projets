/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 06:59:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/10 17:36:51 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

static t_arg	*add_link(t_arg **av, char *str, char *path, int index)
{
	t_arg	*new;
	t_arg	*tmp;

	tmp = *av;
	new = (t_arg *)malloc(sizeof(t_arg));
	new->str = ft_strdup(str);
	new->path = ft_strdup(path);
	new->len = ft_strlen(str);
	new->index = index - 1;
	new->select = 0;
	new->next = NULL;
	if (*av == NULL)
		return (new);
	else
	{
		while ((*av)->next != NULL)
			*av = (*av)->next;
	}
	(*av)->next = new;
	return (tmp);
}

void			create_list(char **av, t_arg **arg)
{
	int		i;
	char	*new_av;

	*arg = NULL;
	i = 1;
	while (av[i])
	{
		new_av = ft_strdup(av[i]);
		if (how_many(av[i], '/') != 0)
		{
			free(new_av);
			new_av = ft_strrchr(av[i], '/');
			new_av = ft_strsub(new_av, 1, ft_strlen(new_av));
		}
		*arg = add_link(arg, new_av, av[i], i);
		free(new_av);
		i++;
	}
}

int				find_imax(t_win *win)
{
	t_arg	*tmp;
	int		i;

	i = 0;
	tmp = win->arg;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			get_list(void)
{
	t_win	*win;
	t_ios	term;
	t_wsize	ws;

	init_term(&term);
	win = check_static();
	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		leave_term();
	win->x = ws.ws_row;
	win->y = ws.ws_col;
	win->i_max = find_imax(win);
	check_key(&term, win, &ws);
}
