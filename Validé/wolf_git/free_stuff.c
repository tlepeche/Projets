/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 08:01:45 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/16 08:11:26 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_text(t_env *e)
{
	free(e->t_img);
	free(e->t_data);
	free(e->t_bpp);
	free(e->t_sl);
}

void	free_map(t_env *e)
{
	int i;

	i = 0;
	while (e->map[i])
	{
		free(e->map[i]);
		i++;
	}
	free(e->map);
}

void	free_all(t_env *e)
{
	free_map(e);
	free_text(e);
	exit (0);
}
