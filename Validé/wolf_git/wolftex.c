/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolftex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 05:35:14 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/18 03:27:07 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	**init_file(void)
{
	char	**file;

	file = (char **)malloc(sizeof(char *) * 14);
	file[0] = ft_strdup("./xpm/group.xpm");
	file[1] = ft_strdup("./xpm/gun.xpm");
	file[2] = ft_strdup("./xpm/gunfire.xpm");
	file[3] = ft_strdup("./xpm/Untitled.xpm");
	file[4] = ft_strdup("./xpm/statut.xpm");
	file[5] = ft_strdup("./xpm/LEVEL1.xpm");
	file[6] = ft_strdup("./xpm/SECRET.xpm");
	file[7] = ft_strdup("./xpm/sonic.xpm");
	file[8] = ft_strdup("./xpm/zero.xpm");
	file[9] = ft_strdup("./xpm/megamanx.xpm");
	file[10] = ft_strdup("./xpm/yoshi.xpm");
	file[11] = ft_strdup("./xpm/zero2.xpm");
	file[12] = ft_strdup("./xpm/sprite.xpm");
	file[13] = NULL;
	return (file);
}

void	get_text(t_env *e)
{
	char	**file;
	int		x;
	int		*a;
	int		b;

	file = init_file();
	x = 0;
	a = &e->t_edn;
	while (file[x])
	{
		e->t_img[x] = mlx_xpm_file_to_image(e->mlx, file[x], &e->w, &e->h);
		free(file[x]);
		e->t_data[x] = mlx_get_data_addr(e->t_img[x], &b, &(e->t_sl[x]), a);
		e->t_bpp[x] = b;
		x++;
	}
	free(file);
}

void	init_tex(t_env *e)
{
	e->t_img = (void **)malloc(sizeof(void *) * 13);
	e->t_data = (char **)malloc(sizeof(char *) * 13);
	e->t_bpp = (int *)malloc(sizeof(int) * 13);
	e->t_sl = (int *)malloc(sizeof(int) * 13);
	get_text(e);
}
