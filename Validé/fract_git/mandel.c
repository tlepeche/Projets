/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 06:09:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/24 07:35:14 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			init_mandel(int x, int y, t_env *e)
{
	e->f->cre = 1.5 * (x - W_WIDTH / 2) / (W_WIDTH * e->zoom / 2) - 0.7;
	e->f->cim = 1.5 * (y - W_HEIGHT / 2) / (W_HEIGHT * e->zoom / 2);
	e->f->newre = 0 + e->f->x;
	e->f->newim = 0 + e->f->y;
	e->f->oldre = 0;
	e->f->oldim = 0;
}

inline int		iter_mandel(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->iter_max)
	{
		e->f->oldre = e->f->newre;
		e->f->oldim = e->f->newim;
		e->f->newre = pow(e->f->oldre, 2) - pow(e->f->oldim, 2) +
			e->f->cre + e->mouse_x;
		e->f->newim = 2 * e->f->oldre * e->f->oldim + e->f->cim + e->mouse_y;
		if ((pow(e->f->newre, 2) + pow(e->f->newim, 2)) > 4)
			break ;
		i++;
	}
	return (i);
}

void			mandel(t_env *e)
{
	int x;
	int	y;
	int i;
	int	pxl;

	e->fract = 2;
	x = 0;
	while (x <= W_WIDTH)
	{
		y = 0;
		while (y <= W_HEIGHT)
		{
			init_mandel(x, y, e);
			i = iter_mandel(e);
			pxl = x * e->bpp / 8 + y * e->sl;
			e->data[pxl] = get_red(i, e);
			e->data[pxl + 1] = get_green(i, e);
			e->data[pxl + 2] = get_blue(i, e);
			y++;
		}
		x++;
	}
}

void			move_mandel(int x, int y, t_env *e)
{
	e->f->x = (double)(x - W_WIDTH / 2) / (double)(W_WIDTH / 2);
	e->f->y = (double)(y - W_HEIGHT / 2) / (double)(W_HEIGHT / 2);
	mandel(e);
}

void			mouse_mandel(int button, int x, int y, t_env *e)
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
	mandel(e);
}
