/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 07:36:03 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 22:30:01 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player(t_env *e)
{
	e->posx = 2;
	e->posy = 11;
	e->dirx = 1;
	e->diry = 0;
	e->planx = 0;
	e->plany = -0.66;
	e->open = 0;
	e->door = 0;
	e->text = 0;
}

void	init_x(t_env *e)
{
	if (e->drx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->prx - e->mapx) * e->deltax;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->prx) * e->deltax;
	}
}

void	init_y(t_env *e)
{
	if (e->dry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->pry - e->mapy) * e->deltay;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->pry) * e->deltay;
	}
}

void	new_mapx(t_env *e)
{
	e->sidedistx += e->deltax;
	e->mapx += e->stepx;
	if (e->stepx < 0)
		e->side = 0;
	else
		e->side = 1;
}

void	new_mapy(t_env *e)
{
	e->sidedisty += e->deltay;
	e->mapy += e->stepy;
	if (e->stepy < 0)
		e->side = 2;
	else
		e->side = 3;
}
