/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 10:25:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 22:05:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		loop_hook(t_env *e)
{
	expose_hook(e);
	return (0);
}

void	open_secret(t_env *e)
{
	e->map[23][3] = '0';
	e->map[24][3] = '0';
	e->time = 0;
	e->tp = 1;
}

int		nearby_d(t_env *e)
{
	if ((e->posx - 7) <= 2 && (e->posx - 7) >= -1)
		if ((e->posy - 9) <= 1 && (e->posy - 9) >= -1)
			return (1);
	return (0);
}

void	draw(t_env *e, int start)
{
	t_square	sqr;
	int			i;
	int			t_y;
	int			pxl;
	float		d;

	d = (start + e->wall_h / 2 - HEIGHT / 2);
	t_y = ((d * TEX_H) / e->wall_h);
	if (e->side == 0 || e->side == 3)
		sqr.x = ((e->xpm % 5) * 64 - e->t_x + 63);
	else
		sqr.x = ((e->xpm % 5) * 64 + e->t_x);
	sqr.y = ((e->xpm / 5) * 64 + t_y);
	pxl = (sqr.x * (e->t_bpp[0] / 8) + sqr.y * e->t_sl[0]);
	i = e->x * (e->bpp / 8) + start * e->sl;
	if (sqr.x <= 64 - e->door)
	{
		e->data[i] = e->t_data[0][pxl];
		e->data[i + 1] = e->t_data[0][pxl + 1];
		e->data[i + 2] = e->t_data[0][pxl + 2];
	}
}

void	open_door(t_env *e, int start, int end)
{
	while (start <= end)
	{
		e->door += 0.0001;
		draw(e, start);
		if (e->door >= 64)
		{
			e->map[8][7] = '0';
			e->open = 0;
		}
		start++;
	}
}
