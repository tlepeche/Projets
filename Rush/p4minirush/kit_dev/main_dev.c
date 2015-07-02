/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/27 16:13:55 by gallard           #+#    #+#             */
/*   Updated: 2015/02/03 19:02:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		p4_getmove_yourlogin(t_grid *grid, t_case color, int turn_count);
int		p4_getmove_nalcaraz(t_grid *grid, t_case color, int turn_count);
int		p4_getmove_sduprey(t_grid *grid, t_case color, int turn_count);

int		main(void)
{
	t_grid		grid;
	int			move;
	int			i;

	p4_init(&grid);
	printf("Vous avez les jaunes !\n");
	p4_disp(&grid);
	
	i = 0;
	while (1)
	{
		srand(time(0));
		// Block: Human
		printf("1234567\nJouer [1-7]: ");
//		scanf("%d", &move);
//		--move;
		move = p4_getmove_nalcaraz(&grid, JAUNE, i);
//		move = p4_getmove_sduprey(&grid, JAUNE, i);
		printf("%d\n", move);
		p4_play(&grid, move, JAUNE);
		p4_disp(&grid);
		if (p4_won(&grid, move))
		{
			puts("YOU WON!");
			break ;
		}
		i++;

		// Block: AI
		puts("Au ROUGE (votre IA):");
//		scanf("%d", &move);
//		printf("%d\n", move);
		move = p4_getmove_sduprey(&grid, ROUGE, i);
//		move = p4_getmove_nalcaraz(&grid, ROUGE, i);
//		move = p4_getmove_yourlogin(&grid, ROUGE, i);
//		--move;
		p4_play(&grid, move, ROUGE);
		p4_disp(&grid);
		if (p4_won(&grid, move))
		{
			puts("COMPUTER WON!");
			break ;
		}
		if (i > (GRID_W * GRID_H))
			exit (0);
		i++;
	}
	return (0);
}
