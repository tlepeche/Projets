/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 01:18:12 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:58:51 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	save_solution(t_env *e)
{
	e->best_move = ft_strlen(e->str);
	if (e->moves != NULL)
		free(e->moves);
	e->moves = ft_strdup(e->str);
}

void	test_move(t_pile *tmp_a, t_pile *tmp_b, t_env *e, int i)
{
	t_pile	*tmp_a2;
	t_pile	*tmp_b2;

	tmp_a2 = (t_pile *)malloc(sizeof(t_pile));
	pile_cpy(&tmp_a2, &tmp_b2, tmp_a, tmp_b);
	e->str[e->nb_test - 1] = choose_move(i);
	e->str[e->nb_test] = '\0';
	make_moves(e->str[e->nb_test - 1], &tmp_a2, &tmp_b2);
	e->status[e->nb_test] = register_status(tmp_a2, tmp_b2);
	e->status[e->nb_test + 1] = NULL;
	if (compare_status(e->status, e->nb_test) == 1)
	{
		if (check_list(tmp_a2, tmp_b2) == 1)
		{
			if (ft_strlen(e->str) < e->best_move)
				save_solution(e);
		}
		test_tree(&tmp_a2, &tmp_b2, e);
	}
	free_pile(&tmp_a2);
	free_tab(e->status[e->nb_test]);
}

void	test_tree(t_pile **a, t_pile **b, t_env *e)
{
	int		i;
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	tmp_a = (t_pile *)malloc(sizeof(t_pile));
	tmp_b = (t_pile *)malloc(sizeof(t_pile));
	if (e->nb_test < e->max_move && e->nb_test < e->best_move)
	{
		pile_cpy(&tmp_a, &tmp_b, *a, *b);
		e->nb_test += 1;
		i = 0;
		while (i <= 7)
		{
			test_move(tmp_a, tmp_b, e, i);
			i++;
		}
		e->nb_test -= 1;
		free_pile(&tmp_a);
		free_pile(&tmp_b);
	}
}

void	init_tree(t_pile **a, t_pile **b, t_env *e)
{
	int		len;

	e->moves = NULL;
	len = len_pile(*a);
	e->status = (char ***)malloc(sizeof(char **) * (len * log(len) + 5));
	e->status[0] = register_status(*a, *b);
	e->max_move = len * log(len) + 3;
	e->best_move = len * log(len) + 3;
	e->nb_test = 0;
	test_tree(a, b, e);
	free_tab(e->status[0]);
	free(e->status);
}
