/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:04:01 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/06 18:25:35 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

void	clr_screen(void)
{
	char	*commande;

	if ((commande = tgetstr("cl", NULL)) == NULL)
		leave_term();
	tputs(commande, 0, &ft_putterm);
}

int		ft_putterm(int c)
{
	int	fd;

	fd = open("/dev/tty", O_WRONLY);
	if (fd == -1)
		leave_term();
	ft_putchar_fd((char)c, fd);
	close(fd);
	return (0);
}
