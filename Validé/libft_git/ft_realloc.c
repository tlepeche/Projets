/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 07:34:57 by tlepeche          #+#    #+#             */
/*   Updated: 2014/11/17 01:27:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*p_ptr;

	if (!ptr)
		return (NULL);
	p_ptr = (void *)malloc(size);
	if (!p_ptr)
		return (NULL);
	free(ptr);
	p_ptr = memcpy(p_ptr, ptr, ft_strlen(ptr));
	return (p_ptr);
}
