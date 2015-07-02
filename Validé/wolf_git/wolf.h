/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 01:13:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/19 00:16:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include "X.h"

# define W_WIDTH 1809
# define W_HEIGHT 1111
# define WIDTH 1809
# define HEIGHT 900
# define ABS(x) ((x >= 0) ? x : -(x))
# define MAP_FILE "./wolf.map"
# define MVT_SPD 0.4
# define ROT M_PI / 20
# define TEX_W 64
# define TEX_H 64

typedef	struct	s_sprite
{
	double		x;
	double		y;
	int			nb;
}				t_sprite;

typedef struct	s_square
{
	int			x;
	int			y;
}				t_square;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	char		**map;
	int			time;
	int			tp;
	int			open;
	double		door;
	int			mapx;
	int			mapy;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	int			x;
	double		prx;
	double		pry;
	double		drx;
	double		dry;
	double		coef;
	double		sidedistx;
	double		sidedisty;
	double		deltax;
	double		deltay;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			wall_h;
	double		floorxwall;
	double		floorywall;
	double		f_hit_x;
	double		f_hit_y;
	double		currentdist;
	double		weight;
	double		cur_floorx;
	double		cur_floory;
	int			t_floorx;
	int			t_floory;
	int			text;
	int			xpm;
	double		wallx;
	int			t_x;
	int			w;
	int			h;
	void		**t_img;
	char		**t_data;
	int			*t_bpp;
	int			*t_sl;
	int			t_edn;
	int			mid_dist;
	double		buf[WIDTH];
	double		spdst_x;
	double		spdst_y;
	double		sp_coef;
	double		transfx;
	double		transfy;
	int			sp_loc;
	int			sp_h;
	int			sp_w;
	int			start_y;
	int			start_x;
	int			end_x;
	int			end_y;
	int			sp_x;
	int			sp_y;
	int			sptx_x;
	int			sptx_y;
}				t_env;

void			raycasting(t_env *e);
void			left(t_env *e);
void			right(t_env *e);
void			down(t_env *e);
void			up(t_env *e);
void			init_tex(t_env *e);
void			draw_bg(t_env *e);
void			new_mapx(t_env *e);
void			new_mapy(t_env *e);
void			init_x(t_env *e);
void			init_y(t_env *e);
void			floor_casting(t_env *e);
void			init_player(t_env *e);
void			draw_gun(t_env *e);
void			draw_gunfire(t_env *e);
void			draw_impact(t_env *e);
void			draw_status(t_env *e);
int				nearby_d(t_env *e);
void			open_door(t_env *e, int start, int end);
int				loop_hook(t_env *e);
void			open_secret(t_env *e);
int				expose_hook(t_env *e);
void			draw_title(t_env *e);
void			draw_secret(t_env *e);
void			draw_wall(t_env *e, int start, int end);
void			draw_spwall(t_env *e, int start, int end, int j);
void			draw_sp_multiwall(t_env *e, int start, int end, int j);
void			choose_draw(t_env *e, int start, int end);
void			sprite_casting(t_env *e);
void			free_all(t_env *e);

#endif
