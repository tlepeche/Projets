/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:01:04 by tlepeche          #+#    #+#             */
/*   Updated: 2014/11/06 20:06:56 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void *a, void *b)
{
	unsigned char	*conva;
	unsigned char	*convb;
	char			c;

	conva = (unsigned char *)a;
	convb = (unsigned char*)b;
	c = *convb;
	*convb = *conva;
	*conva = c;
}
