/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 03:40:31 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/09 23:15:47 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void			swap_a(t_pile **a)
{
	t_pile *tmp;

	if (*a != NULL && (*a)->prev != NULL)
	{
		tmp = *a;
		*a = (*a)->prev;
		tmp->prev = tmp->prev->prev;
		(*a)->prev = tmp;
	}
}

void			swap_b(t_pile **b)
{
	t_pile *tmp;

	if (*b != NULL && (*b)->prev != NULL)
	{
		tmp = *b;
		*b = (*b)->prev;
		tmp->prev = tmp->prev->prev;
		(*b)->prev = tmp;
	}
}

void			double_swap(t_pile **a, t_pile **b)
{
	if (*a != NULL && (*a)->prev != NULL &&
			*b != NULL && (*b)->prev != NULL)
	{
		swap_a(a);
		swap_b(b);
	}
}
