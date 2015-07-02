/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 22:27:13 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/02 19:28:21 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <libft.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>

typedef struct termios	t_ios;
typedef struct winsize	t_wsize;

typedef struct		s_arg
{
	char			*str;
	char			*path;
	int				len;
	int				index;
	int				select;
	int				x;
	int				y;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_win
{
	int				x;
	int				y;
	int				max_y;
	int				i_max;
	int				position;
	int				stop;
	t_ios			ori_term;
	t_arg			*arg;
}					t_win;

t_win				*check_static(void);
t_arg				*delete_link(t_win *win, int index);
void				init_term(t_ios *term);
void				create_list(char **av, t_arg **arg);
void				get_list(void);
void				move_list(t_win *win, t_ios *term, int x, int y);
void				check_key(t_ios *term, t_win *win, t_wsize *ws);
void				check_move(char *buf, int *y, int *x, t_win *win);
void				clr_screen(void);
void				print_arg(t_arg **av, t_win *win, int position, int space);
void				print_selected(t_arg *arg);
void				select_all(t_arg *arg);
void				select_reverse(t_arg *arg);
void				leave_term(void);
int					find_imax(t_win *win);
int					find_space(t_arg *av);
int					check_win(t_win *win);
int					reset_val(t_ios *term, t_wsize *ws, int sig);
int					reset_param(t_ios *term);
int					ft_putterm(int c);

#endif
