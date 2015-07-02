/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:19:02 by tlepeche          #+#    #+#             */
/*   Updated: 2014/11/08 23:34:52 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ')
		return (1);
	return (0);
}
