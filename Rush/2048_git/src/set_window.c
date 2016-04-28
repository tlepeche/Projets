/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 23:16:28 by sduprey           #+#    #+#             */
/*   Updated: 2015/03/01 07:40:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wkw.h>

void	set_window(WINDOW **board, int max_x, int max_y, t_env *e)
{
	int		i;
	int		j;
	int		h;
	int		w;

	h = set_case_size(max_y, e);
	w = set_case_size(max_x, e);
	i = 0;
	while (i < e->gs)
	{
		j = 0;
		while (j < e->gs)
		{
			board[(i * e->gs) + j] = subwin(stdscr, h, w, h * i + 3, w * j);
			wborder(board[(i * e->gs) + j],
					'|', '|', '-', '-', '+', '+', '+', '+');
			j++;
		}
		i++;
	}
}
