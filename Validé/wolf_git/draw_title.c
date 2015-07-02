/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_title.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:54:07 by tlepeche          #+#    #+#             */
/*   Updated: 2014/12/24 07:21:15 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_secret(t_env *e)
{
	int x;
	int y;
	int i;
	int pxl;
	int tmp;

	x = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 300)
		{
			tmp = (WIDTH / 2 - 450 + x);
			i = tmp * (e->bpp / 8) + (HEIGHT / 2 - 150 + y) * e->sl;
			pxl = x * (e->t_bpp[6] / 8) + y * e->t_sl[6];
			if (e->t_data[6][pxl] != 0)
			{
				e->data[i] = e->t_data[6][pxl];
				e->data[i + 1] = e->t_data[6][pxl + 1];
				e->data[i + 2] = e->t_data[6][pxl + 2];
			}
			y++;
		}
		x++;
	}
}

void	draw_title(t_env *e)
{
	int x;
	int y;
	int i;
	int pxl;
	int tmp;

	x = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 300)
		{
			tmp = (WIDTH / 2 - 450 + x);
			i = tmp * (e->bpp / 8) + (HEIGHT / 2 - 150 + y) * e->sl;
			pxl = x * (e->t_bpp[5] / 8) + y * e->t_sl[5];
			if (e->t_data[5][pxl] != 0)
			{
				e->data[i] = e->t_data[5][pxl];
				e->data[i + 1] = e->t_data[5][pxl + 1];
				e->data[i + 2] = e->t_data[5][pxl + 2];
			}
			y++;
		}
		x++;
	}
}
