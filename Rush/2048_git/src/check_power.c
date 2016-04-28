/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_power.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:17:29 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/01 08:08:17 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int			check_power(int nb)
{
	float fl_nb;

	fl_nb = (float)nb;
	while (fl_nb >= 2)
		fl_nb /= 2.00;
	if (fl_nb == 1.00)
		return (1);
	return (0);
}
