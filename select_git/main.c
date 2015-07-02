/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 22:12:54 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/09 19:45:54 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

t_win		*check_static(void)
{
	static t_win *arg;

	if (!arg)
		arg = (t_win *)malloc(sizeof(t_win));
	return (arg);
}

static void	sig_handler(int signum)
{
	t_ios	term;
	t_wsize	ws;
	char	str[2];

	if (signum == SIGCONT || signum == SIGWINCH)
	{
		reset_val(&term, &ws, 1);
		signal(SIGTSTP, &sig_handler);
	}
	else if (signum == SIGINT || signum == SIGTERM || signum == SIGQUIT)
		leave_term();
	else if (signum == SIGTSTP)
	{
		if (isatty(1))
		{
			reset_val(&term, &ws, 1);
			str[0] = term.c_cc[VSUSP];
			str[1] = '\0';
			tputs(tgetstr("ve", NULL), 0, &ft_putterm);
			tputs(tgetstr("te", NULL), 0, &ft_putterm);
			ioctl(0, TIOCSTI, str);
			signal(SIGTSTP, SIG_DFL);
		}
	}
}

void		init_term(t_ios *term)
{
	char	*new_term;

	if ((new_term = getenv("TERM")) == NULL)
		leave_term();
	if (tgetent(NULL, new_term) == ERR)
		leave_term();
	if (tcgetattr(0, term) == -1)
		leave_term();
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		leave_term();
}

static void	catch_signal(void)
{
	signal(SIGWINCH, &sig_handler);
	signal(SIGCONT, &sig_handler);
	signal(SIGINT, &sig_handler);
	signal(SIGQUIT, &sig_handler);
	signal(SIGTERM, &sig_handler);
	signal(SIGTSTP, &sig_handler);
}

int			main(int ac, char **av)
{
	t_win			*win;
	char			*origin_term;

	catch_signal();
	if (ac > 1)
	{
		win = check_static();
		if ((origin_term = getenv("TERM")) == NULL)
			exit(0);
		if (tgetent(NULL, origin_term) == ERR)
			exit(0);
		if (tcgetattr(0, &(win->ori_term)) == -1)
			exit(0);
		tputs(tgetstr("ti", NULL), 0, &ft_putterm);
		create_list(av, &(win->arg));
		get_list();
	}
	return (0);
}
