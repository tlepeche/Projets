/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_resolver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 20:42:52 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/03 17:17:39 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

static void	choose_print(t_env *e)
{
	if (e->counter == 1)
		print_counter(e->best_move);
	if (e->details == 0 && e->counter == 0)
		ft_putchar('\n');
}

void		resolve_pile(t_pile **a, t_pile **b, t_env *e)
{
	t_pile *t_a;
	t_pile *t_b;

	pile_cpy(&t_a, &t_b, *a, *b);
	if (check_list(*a, *b) != 1)
	{
		if (e->pile_len >= 7)
		{
			e->get_min = 0;
			insert_sort(a, b, e, e->pile_len);
		}
		else
			init_tree(a, b, e);
		analyse_move(&e->str);
		if (e->details == 1)
			print_details(e->moves, &t_a, &t_b);
		else
			print_str(e->moves);
		if (e->counter == 1)
			print_counter(e->best_move);
	}
	else
		choose_print(e);
}
