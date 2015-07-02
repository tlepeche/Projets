/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:49:44 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/18 14:50:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	join_line(t_lbx ent, t_pts a, int x, int y)
{
	t_pts	c;

	c = get_point(y + 1, x, ent.loc[y + 1][x], ent);
	create_line(a, c, ent);
}

int		expose_hook(t_lbx *ent)
{
	int		x;
	int		y;
	t_pts	a;
	t_pts	b;

	y = 0;
	while (y++ < ent->loc[0][0])
	{
		x = 0;
		while (x++ < ent->loc[y][0])
		{
			a = get_point(y, x, ent->loc[y][x], *ent);
			b = get_point(y, x + 1, ent->loc[y][x + 1], *ent);
			if (x < ent->loc[y][0])
				create_line(a, b, *ent);
			if (y < ent->loc[0][0] && x <= ent->loc[y + 1][0])
				join_line(*ent, a, x, y);
		}
	}
	return (0);
}

int		keyrelease(int keycode, t_lbx *ent)
{
	if (keycode == 65361)
		ent->left = 0;
	if (keycode == 65363)
		ent->right = 0;
	if (keycode == 65362)
		ent->up = 0;
	if (keycode == 65364)
		ent->down = 0;
	if (keycode == 65451 || keycode == 61)
		ent->zoom_up = 0;
	if (keycode == 65453 || keycode == 45)
		ent->zoom_down = 0;
	return (0);
}

int		keypress(int keycode, t_lbx *ent)
{
	if (keycode == 65361)
		ent->left = 1;
	if (keycode == 65363)
		ent->right = 1;
	if (keycode == 65362)
		ent->up = 1;
	if (keycode == 65364)
		ent->down = 1;
	if (keycode == 65451 || keycode == 61)
		ent->zoom_up = 1;
	if (keycode == 65453 || keycode == 45)
		ent->zoom_down = 1;
	return (0);
}

int		key_hook(int keycode, t_lbx *ent)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 102)
		ent->swap = (ent->swap + 1) % 2;
	if (ent->left == 1)
		ent->width = ent->width - 10;
	if (ent->right == 1)
		ent->width = ent->width + 10;
	if (ent->up == 1)
		ent->height = ent->height - 10;
	if (ent->down == 1)
		ent->height = ent->height + 10;
	if (ent->zoom_up == 1)
		if (ent->size < 2147483647)
			ent->size = ent->size + 1;
	if (ent->zoom_down == 1)
		if (ent->size > 1)
			ent->size = ent->size - 1;
	mlx_clear_window(ent->mlx, ent->winx);
	keyrelease(keycode, ent);
	expose_hook(ent);
	return (0);
}
