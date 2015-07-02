/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 23:25:01 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:54:18 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft.h"
# include <math.h>

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*prev;
}					t_pile;

typedef struct		s_coord
{
	int				val;
	int				st_pos;
	int				end_pos;
}					t_coord;

typedef struct		s_env
{
	int				details;
	int				counter;
	size_t			max_move;
	size_t			nb_test;
	size_t			best_move;
	char			*moves;
	char			*str;
	char			***status;
	int				pile_len;
	int				get_min;
	int				len;
}					t_env;

void				swap_a(t_pile **a);
void				swap_b(t_pile **a);
void				double_swap(t_pile **a, t_pile **b);

void				push_a(t_pile **a, t_pile **b);
void				push_b(t_pile **a, t_pile **b);

void				rotate_a(t_pile **a);
void				rotate_b(t_pile **a);
void				double_rotate(t_pile **a, t_pile **b);

void				r_rotate_a(t_pile **a);
void				r_rotate_b(t_pile **a);
void				double_r_rotate(t_pile **a, t_pile **b);

int					check_chain(char **av);
int					check_pile(t_pile *a);

int					check_list(t_pile *a, t_pile *b);
int					check_pile(t_pile *a);
void				resolve_pile(t_pile **a, t_pile **b, t_env *e);

void				add_pile(t_pile **a, int nb);
void				free_pile(t_pile **a);
int					len_pile(t_pile *a);
void				pile_cpy(t_pile **t_a, t_pile **t_b, t_pile *a, t_pile *b);

void				make_moves(char c, t_pile **a, t_pile **b);
void				analyse_move(char **str);
char				choose_move(int i);

int					check_option(char *str, t_env *e);
void				test_tree(t_pile **a, t_pile **b, t_env *e);

void				print_result(t_pile *a, t_pile *b);
void				print_details(char *str, t_pile **a, t_pile **b);
void				print_counter(size_t moves);
void				print_str(char *str);

char				**register_status(t_pile *a, t_pile *b);
void				init_tree(t_pile **a, t_pile **b, t_env *e);
int					compare_status(char ***status, int cur);
void				split_pile(t_pile **a, t_pile **b, t_env *e);

void				insert_sort(t_pile **a, t_pile **b, t_env *e, int len);
void				move(t_pile **a, t_pile **b, t_coord *min, t_env *e);
int					choose(t_coord *min, t_coord *min2);
void				find_min(t_pile **a, int len, t_coord *min1, t_coord *min2);

#endif
