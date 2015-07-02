/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 00:27:17 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/18 16:20:20 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "X.h"

# define ABS(x) ((x < 0) ? -x : x)
# define HEIGHT	1280
# define WIDTH  800

# define COLOR_UP 0x955628
# define COLOR_MID 0xFFFFFF
# define COLOR_DOWN 0x3A9d23

typedef struct	s_lbx
{
	void		*mlx;
	void		*winx;
	char		*av;
	int			**loc;
	int			size;
	int			width;
	int			height;
	int			up;
	int			down;
	int			left;
	int			right;
	int			zoom_up;
	int			zoom_down;
	int			swap;
}				t_lbx;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	float		isox;
	float		isoy;
}				t_pts;

int				get_color(t_pts a, int i, t_pts coef, t_lbx ent);
void			create_line(t_pts a, t_pts b, t_lbx ent);
int				*convert(char *line);
t_pts			get_point(int x, int y, int z, t_lbx ent);
int				**get_location(t_lbx *ent);
void			join_line(t_lbx ent, t_pts a, int x, int y);
int				expose_hook(t_lbx *ent);
int				key_hook(int keycode, t_lbx *ent);
int				keypress(int keycode, t_lbx *ent);
int				keyrelease(int keycode, t_lbx *ent);
int				find_nb_line(char *str);
void			print_error(int err);

#endif
