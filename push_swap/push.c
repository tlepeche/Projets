/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 03:56:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/18 10:38:11 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_a(t_pile **a, t_pile **b)
{
	t_pile *tmp;

	if (*a != NULL)
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->prev;
		(*b)->prev = tmp;
	}
}

void	push_b(t_pile **a, t_pile **b)
{
	t_pile *tmp;

	if (*a != NULL)
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->prev;
		(*b)->prev = tmp;
	}
}
