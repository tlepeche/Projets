/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 04:02:16 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/12 01:16:22 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void			r_rotate_a(t_pile **a)
{
	t_pile *tmp;
	t_pile *tmp2;

	if (*a != NULL && (*a)->prev != NULL)
	{
		tmp = *a;
		tmp2 = *a;
		while (tmp->prev != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->prev;
		}
		tmp->prev = *a;
		*a = tmp;
		tmp2->prev = NULL;
	}
}

void			r_rotate_b(t_pile **a)
{
	t_pile *tmp;
	t_pile *tmp2;

	if (*a != NULL && (*a)->prev != NULL)
	{
		tmp = *a;
		tmp2 = *a;
		while (tmp->prev != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->prev;
		}
		tmp->prev = *a;
		*a = tmp;
		tmp2->prev = NULL;
	}
}

void			double_r_rotate(t_pile **a, t_pile **b)
{
	if (*a != NULL && (*a)->prev != NULL &&
			*b != NULL && (*b)->prev != NULL)
	{
		r_rotate_a(a);
		r_rotate_b(b);
	}
}
