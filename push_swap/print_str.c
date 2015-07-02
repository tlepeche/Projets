/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:58:30 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:58:42 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

void	print_str_end(char *str, int i)
{
	if (str[i] == 'e')
		ft_putstr("ra");
	else if (str[i] == 'f')
		ft_putstr("sb");
	else if (str[i] == 'g')
		ft_putstr("rrb");
	else if (str[i] == 'h')
		ft_putstr("rb");
	else if (str[i] == 'i')
		ft_putstr("ss");
	else if (str[i] == 'j')
		ft_putstr("rrr");
	else if (str[i] == 'k')
		ft_putstr("rr");
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			ft_putstr("pa");
		else if (str[i] == 'b')
			ft_putstr("pb");
		else if (str[i] == 'c')
			ft_putstr("sa");
		else if (str[i] == 'd')
			ft_putstr("rra");
		else
			print_str_end(str, i);
		if (str[i + 1] && str[i] != ' ')
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
