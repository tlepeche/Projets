/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 07:07:56 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/24 07:32:18 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	print_command(void)
{
	ft_putendl("Invalid command");
	ft_putstr("Command :\n-j for julia\n-m for Madelbrot\n");
	ft_putendl("-t for tricorn\n-J for quadric_julia");
	exit (0);
}

void	choose_color(t_env *e)
{
	e->color = (e->color + 1) % 3;
	if (e->fract == 1)
		julia(e);
	if (e->fract == 2)
		mandel(e);
	if (e->fract == 3)
		tric(e);
	if (e->fract == 4)
		cub_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		get_red(int i, t_env *e)
{
	int color;

	if (i == 0)
		i = 1;
	color = 1;
	if (e->color == 0)
		color = 255 % i;
	else if (e->color == 1)
		color = 250 * log(i);
	else if (e->color == 2)
		color = i * log(e->f->newre + e->f->newim);
	return (color);
}

int		get_green(int i, t_env *e)
{
	int color;

	if (i == 0)
		i = 1;
	color = 1;
	if (e->color == 0)
		color = 250 / i;
	else if (e->color == 1)
		color = 250 / log(e->f->newre * e->f->newim);
	else if (e->color == 2)
		color = i * log(e->f->newre);
	return (color);
}

int		get_blue(int i, t_env *e)
{
	int color;

	if (i == 0)
		i = 1;
	color = 1;
	if (e->color == 0)
		color = 250 * i;
	else if (e->color == 1)
		color = 250 * log(i);
	else if (e->color == 2)
		color = i * log(e->f->newim);
	return (color);
}
