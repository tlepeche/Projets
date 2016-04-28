/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:01:05 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 11:00:06 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WKW_H
# define WKW_H

# include <libft.h>
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

# define UP			'u'
# define DOWN		'd'
# define RIGHT		'r'
# define LEFT		'l'
# define NO_MOVE	'n'
# define EMPTY		'e'
# define FULL		'f'

enum	e_const
{
	WIN_VALUE = 2048,
	GRID_SIZE = 4
};

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_env
{
	int			move;
	int			win_value;
	int			gs;
	int			score;
	int			best;
	int			check;
}				t_env;

void			move_up(int **grid, t_env *e);
void			move_down(int **grid, t_env *e);
void			move_left(int **grid, t_env *e);
void			move_right(int **grid, t_env *e);

void			set_window(WINDOW **board, int max_x, int max_y, t_env *e);
void			fill_grid(WINDOW **board, int **grid, t_env *e);
void			free_grid(int **grid, t_env *e);
void			launch(t_env *e);
void			option(t_env *e);
void			record_score(t_env *e);

int				game_loop(WINDOW **board, int **grid, t_env *e);
int				draw_grid(WINDOW **board, int **grid, t_coord *max, t_env *e);
int				resize_grid(WINDOW **board, int **grid, t_env *e);
int				resolver(int **grid, char move, t_env *e);
int				check_move(int **grid, t_env *e);
int				check_change(int **grid, int **old_grid);
int				check_power(int nb);
int				set_case_size(int max_s, t_env *e);
int				end_game(t_env *e);

int				**cpy_grid(int **grid, t_env *e);
int				**init_grid(t_env *e);

#endif
