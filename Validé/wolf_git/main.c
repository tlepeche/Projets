/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 05:20:34 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/16 10:28:25 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		free_all(e);
	else if (keycode == 102)
		e->text = (e->text + 1) % 2;
	else if (keycode == 65361 || keycode == 97)
		left(e);
	else if (keycode == 65363 || keycode == 100)
		right(e);
	else if (keycode == 65362 || keycode == 119)
		up(e);
	else if (keycode == 65364 || keycode == 115)
		down(e);
	else if (keycode == 32 && nearby_d(e))
		e->open = 1;
	raycasting(e);
	if (e->text == 1)
	{
		sprite_casting(e);
		draw_gun(e);
	}
	draw_status(e);
	if (e->time < 50)
		e->tp == 1 ? draw_secret(e) : draw_title(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		raycasting(e);
		if (e->text == 1)
		{
			sprite_casting(e);
			draw_gunfire(e);
			draw_impact(e);
		}
		draw_status(e);
		if (e->time < 50)
			e->tp == 1 ? draw_secret(e) : draw_title(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	raycasting(e);
	if (e->text == 1)
	{
		sprite_casting(e);
		draw_gun(e);
	}
	draw_status(e);
	if ((int)e->posx == 11 && (int)e->posy == 22)
		open_secret(e);
	if (e->time < 50)
		e->tp == 1 ? draw_secret(e) : draw_title(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	get_map(t_env *e)
{
	int		fd;
	int		nbl;
	char	*line;
	int		i;

	nbl = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbl++;
		free(line);
	}
	close(fd);
	e->map = (char **)malloc(sizeof(char *) * (nbl + 1));
	i = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		e->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	e->map[i] = NULL;
	close(fd);
}

int		main(void)
{
	t_env	e;

	e.tp = 0;
	e.time = 0;
	e.mlx = mlx_init();
	if (e.mlx == NULL)
		exit(0);
	e.win = mlx_new_window(e.mlx, W_WIDTH, W_HEIGHT, "Wolf");
	e.img = mlx_new_image(e.mlx, W_WIDTH, W_HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
	get_map(&e);
	init_player(&e);
	init_tex(&e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
