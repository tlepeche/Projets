/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:17:30 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/18 16:22:09 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_error(int err)
{
	if (err == 1)
		ft_putendl_fd("open() error", 2);
	else
		ft_putendl_fd("close error", 2);
	exit (0);
}

int		find_nb_line(char *str)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		print_error(1);
	i = 0;
	while (get_next_line((int const)fd, &line) > 0)
		i++;
	if (close(fd) == -1)
		print_error(2);
	return (i);
}
