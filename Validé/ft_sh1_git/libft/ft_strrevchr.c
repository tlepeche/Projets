/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 03:20:11 by tlepeche          #+#    #+#             */
/*   Updated: 2015/01/26 05:10:23 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrevchr(const char *s, int c)
{
	int		a;
	char	conv;
	char	*s2;

	if (!s)
		return (NULL);
	conv = (char)c;
	a = ft_strlen(s);
	s2 = ft_strdup((char *)s);
	while (s2[a] != conv)
	{
		s2[a] = '\0';
		a--;
	}
	return (s2);
}
