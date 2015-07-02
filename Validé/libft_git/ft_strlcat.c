/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:20 by tlepeche          #+#    #+#             */
/*   Updated: 2014/11/15 02:44:36 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	unsigned int a;
	unsigned int c;

	a = 0;
	c = ft_strlen(dst);
	if (size < c)
		return (size + ft_strlen(src));
	while (a + c < (size - 1) && src[a] != '\0')
	{
		dst[c + a] = src[a];
		a++;
	}
	dst[c + a] = '\0';
	return (c + ft_strlen(src));
}
