/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:21:17 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/14 17:50:11 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned int	a;
	char			*str;

	a = 0;
	str = (char *)s;
	while (a < n)
	{
		str[a] = '\0';
		a++;
	}
	s = (void *)str;
}
