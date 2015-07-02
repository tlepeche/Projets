/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 05:08:05 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/25 07:23:41 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		check_option(char *str, t_env *e)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'v')
			e->details = 1;
		else if (str[i] == 'i')
			e->counter = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

void	print_counter(size_t moves)
{
	if (moves != 0)
	{
		ft_putstr("Pile triee en ");
		ft_putnbr(moves);
		ft_putendl(" coup(s).");
	}
	else
		ft_putendl("Pile deja triee");
}
