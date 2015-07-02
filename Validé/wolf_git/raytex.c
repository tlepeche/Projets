/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 06:59:09 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 22:29:22 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_ray(t_env *e)
{
	e->prx = e->posx;
	e->pry = e->posy;
	e->mapx = (int)e->prx;
	e->mapy = (int)e->pry;
	e->coef = -2 * (double)e->x / (double)WIDTH + 1;
	e->drx = e->dirx + e->planx * e->coef;
	e->dry = e->diry + e->plany * e->coef;
	e->deltax = sqrt(1 + pow(e->dry, 2) / pow(e->drx, 2));
	e->deltay = sqrt(1 + pow(e->drx, 2) / pow(e->dry, 2));
	e->hit = 0;
}

void			dda(t_env *e)
{
	double	calc_tmp_x;
	double	calc_tmp_y;

	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
			new_mapx(e);
		else
			new_mapy(e);
		if (e->map[e->mapy][e->mapx] != '0')
			e->hit = 1;
	}
	calc_tmp_x = (e->mapx - e->prx + (1 - e->stepx) / 2);
	calc_tmp_y = (e->mapy - e->pry + (1 - e->stepy) / 2);
	if (e->side == 0 || e->side == 1)
		e->walldist = fabs(calc_tmp_x / e->drx);
	else
		e->walldist = fabs(calc_tmp_y / e->dry);
	e->xpm = e->map[e->mapy][e->mapx] - 49;
	if (e->side == 2 || e->side == 3)
		e->wallx = e->prx + (calc_tmp_y / e->dry) * e->drx;
	else
		e->wallx = e->pry + (calc_tmp_x / e->drx) * e->dry;
	e->wallx -= floor(e->wallx);
	e->t_x = (int)(e->wallx * (double)(TEX_W));
}

void			draw_wall(t_env *e, int start, int end)
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
			sqr.x = ((e->xpm % 5) * 64 - e->t_x + 63);
		else
			sqr.x = ((e->xpm % 5) * 64 + e->t_x);
		sqr.y = ((e->xpm / 5) * 64 + t_y);
		pxl = (sqr.x * (e->t_bpp[0] / 8) + sqr.y * e->t_sl[0]);
		i = e->x * (e->bpp / 8) + start * e->sl;
		e->data[i] = e->t_data[0][pxl];
		e->data[i + 1] = e->t_data[0][pxl + 1];
		e->data[i + 2] = e->t_data[0][pxl + 2];
		start++;
	}
}

void			raycasting(t_env *e)
{
	int start;
	int end;

	e->x = 0;
	e->time++;
	while (e->x < WIDTH)
	{
		init_ray(e);
		init_x(e);
		init_y(e);
		dda(e);
		e->buf[e->x] = e->walldist;
		if (e->x == WIDTH / 2)
			e->mid_dist = (e->walldist < 1) ? 1 : 2 * e->walldist;
		e->wall_h = ABS((int)(HEIGHT / e->walldist));
		start = ((HEIGHT - e->wall_h) / 2) < 0 ? 0 : (HEIGHT - e->wall_h) / 2;
		end = (HEIGHT + e->wall_h) / 2;
		end = (end > HEIGHT) ? HEIGHT : end;
		choose_draw(e, start, end);
		floor_casting(e);
		e->x++;
	}
}
