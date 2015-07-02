/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 06:04:27 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/24 07:31:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			init_cub_julia(t_env *e)
{
	e->f->cre = -0.7;
	e->f->cim = 0.27015;
}

inline int		iter_cub_julia(t_env *e)
{
	int i;

	i = 0;
	while (i < e->iter_max)
	{
		e->f->oldre = e->f->newre;
		e->f->oldim = e->f->newim;
		e->f->newre = pow(e->f->oldre, 4) - pow(e->f->oldim, 4)
			+ e->f->cre;
		e->f->newim = 2 * e->f->oldre * e->f->oldim + e->f->cim;
		if ((pow(e->f->newre, 4) + pow(e->f->newim, 4)) > 4)
			break ;
		i++;
	}
	return (i);
}

void			cub_julia(t_env *e)
{
	int x;
	int	y;
	int i;
	int	pxl;

	e->fract = 4;
	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y <= W_HEIGHT)
		{
			e->f->newre = 1.5 * (x - W_WIDTH / 2) /
				(W_WIDTH * e->zoom / 2) + e->mouse_x;
			e->f->newim = 1.5 * (y - W_HEIGHT / 2) /
				(W_HEIGHT * e->zoom / 2) + e->mouse_y;
			i = iter_cub_julia(e);
			pxl = x * e->bpp / 8 + y * e->sl;
			e->data[pxl] = get_red(i, e);
			e->data[pxl + 1] = get_green(i, e);
			e->data[pxl + 2] = get_blue(i, e);
			y++;
		}
		x++;
	}
}

void			move_cub_julia(int x, int y, t_env *e)
{
	e->f->cre = (double)(x - W_WIDTH / 2) / (double)(W_WIDTH / 2);
	e->f->cim = (double)(y - W_HEIGHT / 2) / (double)(W_HEIGHT / 2);
	cub_julia(e);
}

void			mouse_cub_julia(int button, int x, int y, t_env *e)
{
	double	oldx;
	double	oldy;

	oldx = e->mouse_x;
	oldy = e->mouse_y;
	if (button == 4 || button == 5)
	{
		e->mouse_x = ((double)(x - W_WIDTH / 2) /
				(double)(W_WIDTH * e->zoom / 2)) + oldx;
		e->mouse_y = ((double)(y - W_HEIGHT / 2) /
				(double)(W_HEIGHT * e->zoom / 2)) + oldy;
	}
	if (button == 5)
	{
		if (e->zoom < 9223372036854775807 / 2)
			e->zoom *= 2;
		e->iter_max = sqrt(abs(2 * sqrt(abs(1 - sqrt(5 * e->zoom))))) * 50;
	}
	if (button == 4)
	{
		if (e->zoom > 1)
			e->zoom /= 2;
		e->iter_max = sqrt(abs(2 * sqrt(abs(1 - sqrt(5 * e->zoom))))) * 50;
	}
	cub_julia(e);
}
