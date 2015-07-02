/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:38:49 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:52:58 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

static void	move_next(t_pile **a, t_pile **b, t_env *e, int i)
{
	if (check_pile(*a) == 0 || e->get_min == 1)
	{
		e->str[i++] = 'b';
		e->str[i] = '\0';
		push_b(a, b);
	}
	if (e->get_min == 1)
	{
		e->str[i] = 'f';
		e->str[i + 1] = '\0';
		swap_b(b);
	}
}

void		move(t_pile **a, t_pile **b, t_coord *min, t_env *e)
{
	int	rotate;
	int	i;

	rotate = (min->st_pos < min->end_pos) ? 1 : 0;
	i = ft_strlen(e->str);
	if (rotate == 1)
		while (min->st_pos != 0)
		{
			e->str[i++] = 'e';
			e->str[i] = '\0';
			rotate_a(a);
			min->st_pos -= 1;
		}
	else
	{
		while (min->end_pos != 0)
		{
			e->str[i++] = 'd';
			e->str[i] = '\0';
			r_rotate_a(a);
			min->end_pos -= 1;
		}
	}
	move_next(a, b, e, i);
}

int			choose(t_coord *min1, t_coord *min2)
{
	int	pos1;
	int	pos2;

	pos1 = min1->st_pos <= min1->end_pos ? min1->st_pos : min1->end_pos;
	pos2 = min2->st_pos <= min2->end_pos ? min2->st_pos : min2->end_pos;
	if (pos2 < pos1)
		return (2);
	else
		return (1);
}

void		find_min(t_pile **a, int len, t_coord *min1, t_coord *min2)
{
	t_pile	*tmp;
	int		pos;

	tmp = *a;
	pos = 0;
	while (tmp != NULL)
	{
		if (tmp->nb < min1->val)
		{
			min2->val = min1->val;
			min2->st_pos = min1->st_pos;
			min2->end_pos = min1->end_pos;
			min1->val = tmp->nb;
			min1->st_pos = pos;
			min1->end_pos = len - pos;
		}
		else if (tmp->nb < min2->val && tmp->nb != min1->val)
		{
			min2->val = tmp->nb;
			min2->st_pos = pos;
			min2->end_pos = len - pos;
		}
		tmp = tmp->prev;
		pos++;
	}
}
