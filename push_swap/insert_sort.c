/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 17:14:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:40:29 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

void		mega_push(t_pile **a, t_pile **b, t_env *e)
{
	int i;

	e->moves = ft_strdup(e->str);
	i = ft_strlen(e->moves);
	ft_realloc(e->moves, ft_strlen(e->moves) + len_pile(*b) + 1);
	while (*b != NULL)
	{
		push_a(b, a);
		e->moves[i] = 'a';
		i++;
		e->moves[i] = '\0';
	}
	e->best_move = ft_strlen(e->moves);
}

void		resolve_rest(t_pile **a, t_env *e)
{
	char	*str;
	t_pile	*test;

	str = (char *)malloc(sizeof(char) * (ft_strlen(e->str) + 1));
	str = ft_memcpy(str, e->str, ft_strlen(e->str));
	e->str[0] = '\0';
	test = NULL;
	init_tree(a, &test, e);
	e->str = ft_strjoin(str, e->moves);
	free(str);
}

void		init_min(t_coord *min1, t_coord *min2, t_pile *a, int len)
{
	min1->val = a->nb;
	min1->st_pos = 0;
	min1->end_pos = len;
	min2->val = a->prev->nb;
	min2->st_pos = 1;
	min2->end_pos = len;
}

void		move_min(t_pile **a, t_pile **b, t_env *e, int *recurs)
{
	t_coord	min1;
	t_coord	min2;

	init_min(&min1, &min2, *a, e->len);
	find_min(a, e->len, &min1, &min2);
	if (choose(&min1, &min2) == 1 || e->get_min == 1)
	{
		move(a, b, &min1, e);
		e->get_min = 0;
	}
	else
	{
		move(a, b, &min2, e);
		e->get_min = 1;
	}
	if (check_pile(*a) == 0)
	{
		if (e->len > 6)
		{
			*(recurs) = 1;
			insert_sort(a, b, e, e->len - 1);
		}
		else
			resolve_rest(a, e);
	}
}

void		insert_sort(t_pile **a, t_pile **b, t_env *e, int len)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	int		recurs;

	tmp_a = (t_pile *)malloc(sizeof(t_pile));
	tmp_b = (t_pile *)malloc(sizeof(t_pile));
	recurs = 0;
	e->len = len;
	pile_cpy(&tmp_a, &tmp_b, *a, *b);
	if (check_pile(tmp_a) == 0)
		move_min(&tmp_a, &tmp_b, e, &recurs);
	if (recurs == 0)
		mega_push(&tmp_a, &tmp_b, e);
}
