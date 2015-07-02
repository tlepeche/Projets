/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 23:36:02 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/18 16:21:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_pts a, int i, t_pts coef, t_lbx ent)
{
	int		color;
	float	n;
	float	b;

	b = (float)2 / (float)3;
	if (coef.y != 1)
		n = ent.height + 1 / sqrt(6) * (a.x + a.y) + (coef.y * i);
	else
		n = (ent.height + 1 / sqrt(6) * (a.x + a.y) + (coef.x * i * sqrt(b)));
	if (a.isoy - n <= 0.3 && a.isoy - n >= -0.3)
		color = COLOR_MID;
	else if (a.isoy < n)
		color = COLOR_UP;
	else
		color = COLOR_DOWN;
	return (color);
}

void	create_line(t_pts a, t_pts b, t_lbx e)
{
	t_pts	len;
	t_pts	coef;
	t_pts	bkpt;
	int		i;

	len.x = ABS((b.isox - a.isox));
	len.y = ABS((b.isoy - a.isoy));
	coef.x = ((len.x && len.y && ((len.x / len.y) < 1)) ? len.x / len.y : 1);
	coef.y = ((len.x && len.y && ((len.y / len.x) < 1)) ? len.y / len.x : 1);
	i = 0;
	while (a.isox != b.isox || a.isoy != b.isoy)
	{
		mlx_pixel_put(e.mlx, e.winx, a.isox, a.isoy, get_color(a, i, coef, e));
		a.isox = ((b.isox > a.isox) ? a.isox + coef.x : a.isox - coef.x);
		a.isoy = ((b.isoy > a.isoy) ? a.isoy + coef.y : a.isoy - coef.y);
		bkpt.x = ABS((a.isox - b.isox));
		bkpt.y = ABS((a.isoy - b.isoy));
		i++;
		if ((bkpt.x <= 1) && (bkpt.y <= 1))
			break ;
	}
}

int		*convert(char *line)
{
	char	**tab;
	int		*intline;
	int		lenght;
	int		i;

	i = 1;
	lenght = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[lenght])
		lenght++;
	intline = (int *)malloc(sizeof(int *) * (lenght + 1));
	intline[0] = lenght;
	while (i <= lenght)
	{
		intline[i] = ft_atoi(tab[i - 1]);
		free(tab[i - 1]);
		i++;
	}
	free(tab);
	return (intline);
}

t_pts	get_point(int x, int y, int z, t_lbx ent)
{
	t_pts	pts;
	float	a;

	a = (float)2 / (float)3;
	if (ent.swap == 1)
	{
		pts.x = y * ent.size;
		pts.y = x * ent.size;
	}
	else
	{
		pts.x = x * ent.size;
		pts.y = y * ent.size;
	}
	pts.z = z * ent.size / 10;
	pts.isox = ent.width + (sqrt(2) / 2) * (pts.y - pts.x);
	pts.isoy = ent.height + (1 / sqrt(6)) * (pts.x + pts.y) - (sqrt(a) * pts.z);
	return (pts);
}

int		**get_location(t_lbx *ent)
{
	int		fd;
	int		**loc;
	char	*line;
	int		i;

	i = find_nb_line(ent->av);
	fd = open(ent->av, O_RDONLY);
	if (fd == -1)
		print_error(1);
	loc = (int **)malloc(sizeof(int *) * (i + 1));
	loc[0] = (int *)malloc(sizeof(int));
	loc[0][0] = i - 1;
	i = 1;
	while (get_next_line((int const)fd, &line) > 0)
	{
		loc[i++] = convert(line);
		free(line);
	}
	if (close(fd) == -1)
		print_error(2);
	return (loc);
}
