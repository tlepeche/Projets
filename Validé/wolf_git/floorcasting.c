/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 10:25:42 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 23:05:11 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_tlfloor(t_env *e, int start)
{
	int		i;
	int		color;

	if (start > (HEIGHT / 2))
		color = 0x010101;
	else
		color = 0xCCCCCC;
	i = e->x * (e->bpp / 8) + start * e->sl;
	e->data[i] = color;
	e->data[i + 1] = color >> 8;
	e->data[i + 2] = color >> 16;
}

void	draw_floor(t_env *e, int start, int a)
{
	int			i;
	int			pxl;
	t_square	sqr;

	sqr.x = a * 64 + e->t_floorx;
	sqr.y = 1 * 64 + e->t_floory;
	i = e->x * (e->bpp / 8) + start * e->sl;
	pxl = sqr.x * (e->t_bpp[0] / 8) + sqr.y * e->t_sl[0];
	e->data[i] = e->t_data[0][pxl];
	e->data[i + 1] = e->t_data[0][pxl + 1];
	e->data[i + 2] = e->t_data[0][pxl + 2];
}

void	init_floor(t_env *e)
{
	if ((e->side == 0 || e->side == 1) && e->drx > 0)
	{
		e->floorxwall = e->mapx;
		e->floorywall = e->mapy + e->wallx;
	}
	else if ((e->side == 0 || e->side == 1) && e->drx < 0)
	{
		e->floorxwall = e->mapx + 1.0;
		e->floorywall = e->mapy + e->wallx;
	}
	else if ((e->side == 2 || e->side == 3) && e->dry > 0)
	{
		e->floorxwall = e->mapx + e->wallx;
		e->floorywall = e->mapy;
	}
	else if ((e->side == 2 || e->side == 3) && e->dry < 0)
	{
		e->floorxwall = e->mapx + e->wallx;
		e->floorywall = e->mapy + 1.0;
	}
}

void	choose_floor(t_env *e, int start)
{
	if (e->text == 0)
	{
		draw_tlfloor(e, start);
		draw_tlfloor(e, HEIGHT - start);
	}
	else
	{
		draw_floor(e, start, 4);
		draw_floor(e, HEIGHT - start, 3);
	}
}

void	floor_casting(t_env *e)
{
	int start;
	int end;

	init_floor(e);
	start = (HEIGHT + e->wall_h) / 2 + 1;
	start = (start > HEIGHT) ? HEIGHT : start;
	end = HEIGHT;
	while (start <= end)
	{
		e->currentdist = (double)HEIGHT / (double)(2 * start - HEIGHT);
		e->weight = e->currentdist / (double)e->walldist;
		e->cur_floorx = e->weight * e->floorxwall + (1.0 - e->weight) * e->posx;
		e->cur_floory = e->weight * e->floorywall + (1.0 - e->weight) * e->posy;
		e->t_floorx = (int)(e->cur_floorx * 64) % 64;
		e->t_floory = (int)(e->cur_floory * 64) % 64;
		choose_floor(e, start);
		start++;
	}
}
