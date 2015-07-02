/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 23:45:54 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/16 10:15:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_sprite(t_sprite *s)
{
	s[0].x = 15.5;
	s[0].y = 3.5;
	s[0].nb = 0;
	s[1].x = 11.5;
	s[1].y = 8.5;
	s[1].nb = 0;
}

void	init_draw(t_env *e)
{
	e->start_y = -e->sp_h / 2 + HEIGHT / 2;
	if (e->start_y < 0)
		e->start_y = 0;
	e->end_y = e->sp_h / 2 + HEIGHT / 2;
	if (e->end_y > HEIGHT)
		e->end_y = HEIGHT;
	e->start_x = e->sp_loc - e->sp_w / 2;
	if (e->start_x < 0)
		e->start_x = 0;
	e->end_x = e->sp_w / 2 + e->sp_loc;
	if (e->end_x >= WIDTH)
		e->end_x = WIDTH - 1;
}

void	draw_sprite(t_env *e, t_sprite *s, int i)
{
	int d;
	int j;
	int	pxl;
	int	x;

	d = 100 * (e->sp_y + (e->sp_h - HEIGHT) / 2);
	e->sptx_y = ((d * TEX_H) / e->sp_h) / 100;
	x = s[i].nb * 64 + e->sptx_x;
	j = e->sp_x * (e->bpp / 8) + e->sp_y * e->sl;
	pxl = x * (e->t_bpp[12] / 8) + e->sptx_y * e->t_sl[12];
	if (e->t_data[12][pxl] != 0)
	{
		e->data[j] = e->t_data[12][pxl];
		e->data[j + 1] = e->t_data[12][pxl + 1];
		e->data[j + 2] = e->t_data[12][pxl + 2];
	}
}

void	sp_math(t_env *e, t_sprite *s, int i)
{
	e->spdst_x = s[i].x - e->posx;
	e->spdst_y = s[i].y - e->posy;
	e->sp_coef = 1.0 / (e->planx * e->diry - e->dirx * e->plany);
	e->transfx = e->sp_coef * (-e->diry * e->spdst_x + e->dirx * e->spdst_y);
	e->transfy = e->sp_coef * (-e->plany * e->spdst_x + e->planx * e->spdst_y);
	e->sp_loc = (int)((WIDTH / 2) * (1 + e->transfx / e->transfy));
	e->sp_h = abs((int)(HEIGHT / (e->transfy)));
	e->sp_w = abs((int)(HEIGHT / (e->transfy)));
}

void	sprite_casting(t_env *e)
{
	t_sprite	*s;
	int			i;
	int			tmp;

	s = (t_sprite *)malloc(sizeof(t_sprite) * 2);
	init_sprite(s);
	i = -1;
	while (++i < 2)
	{
		sp_math(e, s, i);
		init_draw(e);
		e->sp_x = e->start_x;
		while (e->sp_x < e->end_x)
		{
			tmp = (-e->sp_w / 2 + e->sp_loc);
			e->sptx_x = (100 * (e->sp_x - tmp) * TEX_W / e->sp_w) / 100;
			e->sp_y = e->start_y;
			if (e->transfy > 0 && e->sp_x > 0 &&
					e->sp_x < WIDTH && e->transfy < e->buf[e->sp_x])
				while (e->sp_y++ < e->end_y)
					draw_sprite(e, s, i);
			e->sp_x++;
		}
	}
	free(s);
}
