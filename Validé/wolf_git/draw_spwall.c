/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spwall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 01:01:52 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 23:42:09 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_color(t_env *e)
{
	int color;

	if (e->side == 0)
		color = 0xFF0000;
	else if (e->side == 1)
		color = 0x00FF00;
	else if (e->side == 2)
		color = 0x0000FF;
	else
		color = 0xFFFF00;
	return (color);
}

void	draw_tlwall(t_env *e, int start, int end)
{
	int i;
	int color;

	color = get_color(e);
	while (start <= end)
	{
		i = e->x * (e->bpp / 8) + start * e->sl;
		e->data[i] = color;
		e->data[i + 1] = color >> 8;
		e->data[i + 2] = color >> 16;
		start++;
	}
}

void	draw_sp_multiwall(t_env *e, int start, int end, int j)
{
	t_square	sqr;
	int			i;
	int			t_y;
	int			pxl;
	float		d;

	j *= 10;
	while (start <= end)
	{
		d = (start + e->wall_h / 2 - HEIGHT / 2);
		t_y = ((d * TEX_H) / e->wall_h);
		if (e->side == 0 || e->side == 3)
			sqr.x = (((int)((e->time + j + 20) * 1.4) % 42) * 64 - e->t_x + 63);
		else
			sqr.x = (((int)((e->time + j) * 1.4) % 42) * 64 + e->t_x);
		sqr.y = t_y;
		pxl = (sqr.x * (e->t_bpp[11] / 8) + sqr.y * e->t_sl[11]);
		i = e->x * (e->bpp / 8) + start * e->sl;
		e->data[i] = e->t_data[11][pxl];
		e->data[i + 1] = e->t_data[11][pxl + 1];
		e->data[i + 2] = e->t_data[11][pxl + 2];
		start++;
	}
}

void	draw_spwall(t_env *e, int start, int end, int j)
{
	t_square	sqr;
	int			i;
	int			t_y;
	int			pxl;
	float		d;

	while (start <= end)
	{
		d = (start + e->wall_h / 2 - HEIGHT / 2);
		t_y = ((d * TEX_H) / e->wall_h);
		if (e->side == 0 || e->side == 3)
			sqr.x = (((int)(e->time * 1.5) % 14) * 64 - e->t_x + 63);
		else
			sqr.x = (((int)(e->time * 1.5) % 14) * 64 + e->t_x);
		sqr.y = t_y;
		pxl = (sqr.x * (e->t_bpp[j] / 8) + sqr.y * e->t_sl[j]);
		i = e->x * (e->bpp / 8) + start * e->sl;
		e->data[i] = e->t_data[j][pxl];
		e->data[i + 1] = e->t_data[j][pxl + 1];
		e->data[i + 2] = e->t_data[j][pxl + 2];
		start++;
	}
}

void	choose_draw(t_env *e, int start, int end)
{
	if (e->text == 0)
		draw_tlwall(e, start, end);
	else
	{
		if (e->xpm == 10 && e->open == 1)
			open_door(e, start, end);
		else if (e->xpm >= 11 && e->xpm < 15)
			draw_spwall(e, start, end, (e->xpm - 4));
		else if (e->xpm >= 15)
			draw_sp_multiwall(e, start, end, (e->xpm - 4));
		else
			draw_wall(e, start, end);
	}
}
