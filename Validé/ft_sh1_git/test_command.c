/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 03:22:13 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/03 21:46:02 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	test_command(char *file, t_restart *r)
{
	if (access(file, F_OK) == -1)
		multi_error("./ft_minishell1: ", file, 1, r);
	else
	{
		if (access(file, X_OK) == -1)
			multi_error("./ft_minishell1: ", file, 2, r);
		else
			return ;
	}
}
