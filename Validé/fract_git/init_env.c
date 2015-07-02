/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 07:34:07 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/24 07:36:02 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_var(int ac, char **av, t_env *e)
{
	int		i;

	i = 0;
	e->av = (char **)malloc(sizeof(char *) * ac);
	while (av[i])
	{
		e->av[i] = ft_strdup(av[i]);
		i++;
	}
	e->av[i] = NULL;
	e->f = (t_fract *)malloc(sizeof(t_fract));
	e->f->x = 0;
	e->f->y = 0;
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->zoom = 1;
	e->move = 1;
	e->color = 0;
	e->iter_max = sqrt(abs(2 * sqrt(abs(1 - sqrt(5 * e->zoom))))) * 50;
}
