/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 05:20:47 by tlepeche          #+#    #+#             */
/*   Updated: 2014/12/12 09:18:00 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	right(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(ROT) - e->diry * sin(ROT);
	e->diry = olddirx * sin(ROT) + e->diry * cos(ROT);
	oldplanex = e->planx;
	e->planx = e->planx * cos(ROT) - e->plany * sin(ROT);
	e->plany = oldplanex * sin(ROT) + e->plany * cos(ROT);
}

void	left(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(-ROT) - e->diry * sin(-ROT);
	e->diry = olddirx * sin(-ROT) + e->diry * cos(-ROT);
	oldplanex = e->planx;
	e->planx = e->planx * cos(-ROT) - e->plany * sin(-ROT);
	e->plany = oldplanex * sin(-ROT) + e->plany * cos(-ROT);
}

void	down(t_env *e)
{
	if (e->map[(int)(e->posy - e->diry * MVT_SPD)][(int)(e->posx)] == '0')
		e->posy -= e->diry * MVT_SPD;
	if (e->map[(int)(e->posy)][(int)(e->posx - e->dirx * MVT_SPD)] == '0')
		e->posx -= e->dirx * MVT_SPD;
}

void	up(t_env *e)
{
	if (e->map[(int)(e->posy + e->diry * MVT_SPD)][(int)(e->posx)] == '0')
		e->posy += e->diry * MVT_SPD;
	if (e->map[(int)(e->posy)][(int)(e->posx + e->dirx * MVT_SPD)] == '0')
		e->posx += e->dirx * MVT_SPD;
}
