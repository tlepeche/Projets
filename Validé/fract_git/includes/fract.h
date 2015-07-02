/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 00:03:46 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/24 07:34:47 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft.h"
# include "X.h"
# include <math.h>
# include <mlx.h>
# define W_WIDTH 900
# define W_HEIGHT 750

typedef struct	s_fract
{
	double		cre;
	double		cim;
	double		oldre;
	double		oldim;
	double		newre;
	double		newim;
	double		x;
	double		y;
}				t_fract;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	char		**av;
	int			fract;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
	int			move;
	int			iter_max;
	int			color;
	t_fract		*f;
}				t_env;

void			choose_color(t_env *e);
int				get_red(int i, t_env *e);
int				get_green(int i, t_env *e);
int				get_blue(int i, t_env *e);
void			julia(t_env *e);
void			move_julia(int x, int y, t_env *e);
void			mouse_julia(int button, int x, int y, t_env *e);
void			init_julia(t_env *e);
void			cub_julia(t_env *e);
void			move_cub_julia(int x, int y, t_env *e);
void			mouse_cub_julia(int button, int x, int y, t_env *e);
void			init_cub_julia(t_env *e);
void			mandel(t_env *e);
void			move_mandel(int x, int y, t_env *e);
void			mouse_mandel(int button, int x, int y, t_env *e);
void			tric(t_env *e);
void			move_tric(int x, int y, t_env *e);
void			mouse_tric(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
void			print_command(void);
void			init_var(int ac, char **av, t_env *e);

#endif
