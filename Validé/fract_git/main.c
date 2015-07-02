/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 05:26:06 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/24 07:36:08 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 99)
		choose_color(e);
	if (keycode == 32)
	{
		e->mouse_x = 0;
		e->mouse_y = 0;
		e->zoom = 1;
		expose_hook(e);
	}
	if (keycode == 65307)
		exit (0);
	if (keycode == 102)
		e->move = (e->move + 1) % 2;
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (e->fract == 1 && e->move == 1)
		move_julia(x, y, e);
	else if (e->fract == 2 && e->move == 1)
		move_mandel(x, y, e);
	else if (e->fract == 3 && e->move == 1)
		move_tric(x, y, e);
	else if (e->fract == 4 && e->move == 1)
		move_cub_julia(x, y, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (e->fract == 1)
		mouse_julia(button, x, y, e);
	else if (e->fract == 2)
		mouse_mandel(button, x, y, e);
	else if (e->fract == 3)
		mouse_tric(button, x, y, e);
	else if (e->fract == 4)
		mouse_cub_julia(button, x, y, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		expose_hook(t_env *e)
{
	if (e->av[1] && ft_strcmp(e->av[1], "-j") == 0)
	{
		init_julia(e);
		julia(e);
	}
	else if (e->av[1] && ft_strcmp(e->av[1], "-m") == 0)
		mandel(e);
	else if (e->av[1] && ft_strcmp(e->av[1], "-t") == 0)
		tric(e);
	else if (e->av[1] && ft_strcmp(e->av[1], "-J") == 0)
	{
		init_cub_julia(e);
		cub_julia(e);
	}
	else
		print_command();
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	init_var(ac, av, &e);
	e.mlx = mlx_init();
	if (e.mlx == NULL)
		exit(0);
	e.win = mlx_new_window(e.mlx, W_WIDTH, W_HEIGHT, "Fract'ol");
	e.img = mlx_new_image(e.mlx, W_WIDTH, W_HEIGHT);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sl, &e.endian);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, mouse_move, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
