/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 04:01:11 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/26 05:14:40 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void			rotate_a(t_pile **a)
{
	t_pile	*tmp;

	if (*a != NULL && (*a)->prev != NULL)
	{
		tmp = *a;
		while ((*a)->prev != NULL)
			*a = (*a)->prev;
		(*a)->prev = tmp;
		(*a) = tmp->prev;
		tmp->prev = NULL;
	}
}

void			rotate_b(t_pile **a)
{
	t_pile	*tmp;

	if (*a != NULL && (*a)->prev != NULL)
	{
		tmp = *a;
		while ((*a)->prev != NULL)
			*a = (*a)->prev;
		(*a)->prev = tmp;
		(*a) = tmp->prev;
		tmp->prev = NULL;
	}
}

void			double_rotate(t_pile **a, t_pile **b)
{
	if (*a != NULL && (*a)->prev != NULL &&
			*b != NULL && (*b)->prev != NULL)
	{
		rotate_a(a);
		rotate_b(b);
	}
}
