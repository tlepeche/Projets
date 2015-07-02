/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 04:17:44 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 17:10:00 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_details_end(char *str, t_pile **a, t_pile **b, int i)
{
	if (str[i] == 'i')
	{
		double_swap(a, b);
		ft_putendl("ss");
		print_result(*a, *b);
	}
	else if (str[i] == 'j')
	{
		double_r_rotate(a, b);
		ft_putendl("rrr");
		print_result(*a, *b);
	}
	else if (str[i] == 'k')
	{
		double_rotate(a, b);
		ft_putendl("rr");
		print_result(*a, *b);
	}
	if (str[i + 1])
		ft_putchar('\n');
}

void	print_details_three(char *str, t_pile **a, t_pile **b, int i)
{
	if (str[i] == 'f')
	{
		swap_b(b);
		ft_putendl("sb");
		print_result(*a, *b);
	}
	else if (str[i] == 'g')
	{
		r_rotate_b(b);
		ft_putendl("rrb");
		print_result(*a, *b);
	}
	else if (str[i] == 'h')
	{
		rotate_b(b);
		ft_putendl("rb");
		print_result(*a, *b);
	}
	else
		print_details_end(str, a, b, i);
}

void	print_details_two(char *str, t_pile **a, t_pile **b, int i)
{
	if (str[i] == 'c')
	{
		swap_a(a);
		ft_putendl("sa");
		print_result(*a, *b);
	}
	else if (str[i] == 'd')
	{
		r_rotate_a(a);
		ft_putendl("rra");
		print_result(*a, *b);
	}
	else if (str[i] == 'e')
	{
		rotate_a(a);
		ft_putendl("ra");
		print_result(*a, *b);
	}
	else
		print_details_three(str, a, b, i);
}

void	print_details(char *str, t_pile **a, t_pile **b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{
			push_a(b, a);
			ft_putendl("pa");
			print_result(*a, *b);
		}
		else if (str[i] == 'b')
		{
			push_b(a, b);
			ft_putendl("pb");
			print_result(*a, *b);
		}
		else
			print_details_two(str, a, b, i);
		i++;
	}
}
