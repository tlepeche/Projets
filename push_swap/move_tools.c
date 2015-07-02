/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 03:38:51 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/12 04:49:18 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	make_moves(char c, t_pile **a, t_pile **b)
{
	if (c == 'a')
		push_a(b, a);
	else if (c == 'b')
		push_b(a, b);
	else if (c == 'c')
		swap_a(a);
	else if (c == 'd')
		r_rotate_a(a);
	else if (c == 'e')
		rotate_a(a);
	else if (c == 'f')
		swap_b(b);
	else if (c == 'g')
		r_rotate_b(b);
	else if (c == 'h')
		rotate_b(b);
}

void	analyse_move(char **str)
{
	int		i;

	i = 1;
	while (str[0][i] != '\0')
	{
		if ((str[0][i] == 'c' && str[0][i - 1] == 'f') ||
				(str[0][i] == 'f' && str[0][i - 1] == 'c'))
		{
			str[0][i] = 'i';
			str[0][i - 1] = ' ';
		}
		else if ((str[0][i] == 'd' && str[0][i - 1] == 'g') ||
				(str[0][i] == 'g' && str[0][i - 1] == 'd'))
		{
			str[0][i] = 'j';
			str[0][i - 1] = ' ';
		}
		else if ((str[0][i] == 'e' && str[0][i - 1] == 'h') ||
				(str[0][i] == 'h' && str[0][i - 1] == 'e'))
		{
			str[0][i] = 'k';
			str[0][i - 1] = ' ';
		}
		i++;
	}
}

char	choose_move(int i)
{
	char	c;

	if (i == 0)
		c = 'a';
	else if (i == 1)
		c = 'b';
	else if (i == 2)
		c = 'c';
	else if (i == 3)
		c = 'd';
	else if (i == 4)
		c = 'e';
	else if (i == 5)
		c = 'f';
	else if (i == 6)
		c = 'g';
	else
		c = 'h';
	return (c);
}
