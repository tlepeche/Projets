/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 01:35:17 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/12 05:11:05 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		check_list(t_pile *a, t_pile *b)
{
	if (b != NULL)
		return (0);
	while (a != NULL && a->prev != NULL)
	{
		if (a->prev->nb < a->nb)
			return (0);
		a = a->prev;
	}
	return (1);
}

int		check_rev_list(t_pile *a, t_pile *b)
{
	if (b != NULL)
		return (0);
	while (a != NULL && a->prev != NULL)
	{
		if (a->prev->nb > a->nb)
			return (0);
		a = a->prev;
	}
	return (1);
}

int		check_rev_pile(t_pile *b)
{
	while (b != NULL && b->prev != NULL)
	{
		if (b->prev->nb > b->nb)
			return (0);
		b = b->prev;
	}
	return (1);
}

int		check_pile(t_pile *a)
{
	while (a != NULL && a->prev != NULL)
	{
		if (a->prev->nb < a->nb)
			return (0);
		a = a->prev;
	}
	return (1);
}
