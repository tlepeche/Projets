/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 05:41:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/18 16:43:44 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_lbx	ent;

	if (ac < 2)
	{
		ft_putendl_fd("usage: ./fdf file1", 2);
		return (0);
	}
	ent.size = 10;
	ent.height = 100;
	ent.width = 100;
	ent.swap = 0;
	ent.av = ft_strdup(av[ac - 1]);
	ent.mlx = mlx_init();
	if (ent.mlx == NULL)
		exit(0);
	ent.loc = get_location(&ent);
	ent.winx = mlx_new_window(ent.mlx, HEIGHT, WIDTH, "FdF");
	mlx_hook(ent.winx, KeyPress, KeyPressMask, keypress, &ent);
	mlx_hook(ent.winx, KeyRelease, KeyReleaseMask, keyrelease, &ent);
	mlx_key_hook(ent.winx, key_hook, &ent);
	mlx_expose_hook(ent.winx, expose_hook, &ent);
	mlx_loop(ent.mlx);
	return (0);
}
