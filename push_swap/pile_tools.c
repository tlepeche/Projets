/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 03:34:52 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:56:28 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	print_pile(t_pile *a)
{
	if (a == NULL)
		ft_putstr("Pile vide");
	else
	{
		while (a != NULL)
		{
			ft_putnbr(a->nb);
			if (a->prev != NULL)
				ft_putchar(' ');
			a = a->prev;
		}
	}
	ft_putchar('\n');
}

void		print_result(t_pile *a, t_pile *b)
{
	ft_putstr("a : ");
	print_pile(a);
	ft_putstr("b : ");
	print_pile(b);
	ft_putendl("#######################################");
}

void		free_pile(t_pile **a)
{
	while (*a != NULL)
	{
		free(*a);
		*a = (*a)->prev;
	}
}

int			len_pile(t_pile *a)
{
	int		len;

	len = 0;
	while (a != NULL)
	{
		a = a->prev;
		len++;
	}
	return (len);
}

void		pile_cpy(t_pile **t_a, t_pile **t_b, t_pile *a, t_pile *b)
{
	int		len;

	*t_a = NULL;
	len = len_pile(a);
	if (!len)
		*t_a = NULL;
	while (len)
	{
		r_rotate_a(&a);
		add_pile(t_a, a->nb);
		len--;
	}
	*t_b = NULL;
	len = len_pile(b);
	if (!len)
		*t_b = NULL;
	while (len)
	{
		r_rotate_b(&b);
		add_pile(t_b, b->nb);
		len--;
	}
}
