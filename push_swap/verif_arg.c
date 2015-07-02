/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 05:38:47 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/10 01:19:11 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		check_double(char **av)
{
	int	i;
	int	j;

	i = av[1][0] == '-' ? 2 : 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_size(char *str)
{
	int		i;
	int		sign;
	char	*val_max;
	size_t	len_max;

	sign = str[0] == '-' || str[0] == '+' ? 1 : 0;
	val_max = str[0] == '-' ? "2147483648" : "2147483647";
	len_max = sign == 1 ? 11 : 10;
	if (ft_strlen(str) > len_max)
		return (0);
	else if (ft_strlen(str) == len_max)
	{
		i = 0;
		while (str[i])
		{
			if (str[i + sign] > val_max[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int		check_chain(char **av)
{
	int		i;

	if (av[1])
	{
		i = av[1][0] == '-' ? 2 : 1;
		while (av[i])
		{
			if (ft_isnumber(av[i]) == 0)
				return (0);
			if (check_size(av[i]) == 0)
				return (0);
			i++;
		}
		if (check_double(av) == 0)
			return (0);
	}
	return (1);
}
