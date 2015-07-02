/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:01:19 by tlepeche          #+#    #+#             */
/*   Updated: 2014/12/24 07:21:36 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_gun(t_env *e)
{
	int	x;
	int y;
	int i;
	int	pxl;
	int tmp;

	x = 0;
	while (x < 150 * 4)
	{
		y = 0;
		while (y < 100 * 4)
		{
			tmp = (WIDTH / 2 - 75 * 4 + x);
			i = tmp * (e->bpp / 8) + (HEIGHT - 100 * 4 + y) * e->sl;
			pxl = (x / 4) * (e->t_bpp[1] / 8) + (y / 4) * e->t_sl[1];
			if (e->t_data[1][pxl] != 0)
			{
				e->data[i] = e->t_data[1][pxl];
				e->data[i + 1] = e->t_data[1][pxl + 1];
				e->data[i + 2] = e->t_data[1][pxl + 2];
			}
			y++;
		}
		x++;
	}
}

void	draw_status(t_env *e)
{
	int x;
	int y;
	int i;
	int pxl;

	x = 0;
	while (x < 603 * 3)
	{
		y = 0;
		while (y < 67 * 3)
		{
			i = x * (e->bpp / 8) + (W_HEIGHT - (67 * 3) + y) * e->sl;
			pxl = x / 3 * (e->t_bpp[4] / 8) + y / 3 * e->t_sl[4];
			if (e->t_data[4][pxl] != 0)
			{
				e->data[i] = e->t_data[4][pxl];
				e->data[i + 1] = e->t_data[4][pxl + 1];
				e->data[i + 2] = e->t_data[4][pxl + 2];
			}
			y++;
		}
		x++;
	}
}

void	draw_impact(t_env *e)
{
	int x;
	int y;
	int i;
	int pxl;
	int tmp;

	x = -1;
	while (x++ < 105 / e->mid_dist)
	{
		y = -1;
		while (y++ < 105 / e->mid_dist)
		{
			tmp = (52 / e->mid_dist);
			i = (WIDTH / 2 - tmp + x) * (e->bpp / 8) + \
				(HEIGHT / 2 - tmp + y) * e->sl;
			pxl = x * e->mid_dist * (e->t_bpp[3] / 8) + \
				y * e->mid_dist * e->t_sl[3];
			if (e->t_data[3][pxl] != 0)
			{
				e->data[i] = e->t_data[3][pxl];
				e->data[i + 1] = e->t_data[3][pxl + 1];
				e->data[i + 2] = e->t_data[3][pxl + 2];
			}
		}
	}
}

void	draw_gunfire(t_env *e)
{
	int x;
	int y;
	int i;
	int pxl;
	int tmp;

	x = 0;
	while (x < 150 * 4)
	{
		y = 0;
		while (y < 100 * 4)
		{
			tmp = (WIDTH / 2 - 75 * 4 + x);
			i = tmp * (e->bpp / 8) + (HEIGHT - 100 * 4 + y) * e->sl;
			pxl = (x / 4) * (e->t_bpp[2] / 8) + (y / 4) * e->t_sl[2];
			if (e->t_data[2][pxl] != 0)
			{
				e->data[i] = e->t_data[2][pxl];
				e->data[i + 1] = e->t_data[2][pxl + 1];
				e->data[i + 2] = e->t_data[2][pxl + 2];
			}
			y++;
		}
		x++;
	}
}
