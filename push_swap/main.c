/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 23:22:41 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 18:55:53 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	add_pile(t_pile **a, int nb)
{
	t_pile *new;

	new = (t_pile *)malloc(sizeof(t_pile));
	new->nb = nb;
	if (*a == NULL)
		new->prev = NULL;
	else
		new->prev = *a;
	*a = new;
}

void	create_pile(t_pile **a, char **av, int ac, t_env *e)
{
	int	stop;

	stop = e->pile_len == ac ? 0 : 1;
	while (ac > stop)
	{
		add_pile(a, ft_atoi(av[ac]));
		ac--;
	}
}

void	init_env(t_env *e, char **av, int ac, int *check)
{
	e->details = 0;
	e->counter = 0;
	e->max_move = 0;
	e->best_move = 0;
	if (av[1] && av[1][0] == '-' && ft_isdigit(av[1][1]) == 0)
	{
		*(check) = check_option(av[1], e);
		e->pile_len = ac - 2;
	}
	else
		e->pile_len = ac - 1;
}

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	t_env	e;
	int		check;

	a = NULL;
	b = NULL;
	check = 1;
	init_env(&e, av, ac, &check);
	if (check_chain(av) == 0 || check == 0)
		ft_putendl_fd("Error", 2);
	else if (e.pile_len != 0)
	{
		check = e.pile_len;
		e.str = (char *)malloc(sizeof(char) * (check * log(check) + 1));
		create_pile(&a, av, ac - 1, &e);
		if (e.details == 1)
			print_result(a, b);
		resolve_pile(&a, &b, &e);
	}
	return (0);
}
