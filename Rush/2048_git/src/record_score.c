/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 04:01:20 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 09:20:39 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

void	record_score(t_env *e)
{
	int		fd;
	char	*str;

	fd = open("score.txt", O_CREAT, S_IRWXU);
	fd = open("score.txt", O_RDWR);
	if (e->best < e->score)
	{
		str = (char *)malloc(sizeof(char) * 25);
		str = ft_itoa(e->score);
		write(fd, str, 25);
		free(str);
	}
}
