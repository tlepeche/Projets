/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 06:09:17 by tlepeche          #+#    #+#             */
/*   Updated: 2015/02/26 06:45:00 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	*register_pile(t_pile *a, int len)
{
	char	*status;
	int		i;

	status = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (len)
	{
		status[i] = a->nb + 48;
		rotate_a(&a);
		len--;
		i++;
	}
	status[i] = '\0';
	return (status);
}

char	**register_status(t_pile *a, t_pile *b)
{
	int		len;
	char	**status;
	t_pile	*tmp;

	status = (char **)malloc(sizeof(char *) * 3);
	tmp = a;
	len = len_pile(a);
	status[0] = register_pile(tmp, len);
	tmp = b;
	len = len_pile(b);
	status[1] = register_pile(tmp, len);
	status[2] = NULL;
	free(tmp);
	return (status);
}

int		compare_status(char ***status, int cur)
{
	int		i;

	i = 0;
	while (i < cur)
	{
		if (ft_strcmp(status[i][0], status[cur][0]) == 0 &&
				ft_strcmp(status[i][1], status[i][1]) == 0)
			return (0);
		i++;
	}
	return (1);
}
