/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 01:31:57 by tlepeche          #+#    #+#             */
/*   Updated: 2015/03/23 07:25:26 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>

typedef struct stat	t_stat;

typedef	struct		s_restart
{
	int			stop;
	int			exec;
	int			recurs;
	int			test;
	int			reader;
	int			line;
	char		*file;
}					t_restart;

char				**move_directory(char **av, char **env, t_restart *r);
char				**manage_env(char **env, int ac, char **av);
char				**unset_env(char **env, char **av, int ac);
char				**set_env(char **env, int ac, char **av);
void				exec_bin(char *exe, char **av, char **env, t_restart *r);
void				test_file(char *exe, char **av, char **env, t_restart *r);
int					test_exec(char *exe, char **av, char **env, t_restart *r);
void				test_directory(char **av, char **env, t_restart *r);
char				**create_env(char **env);
char				**change_av(char **av, char **env);
char				*get_home(char **env);
char				*move_home(char **av, char **env);
char				*switch_pwd(char **av, char **env);
int					find_oldpwd(char **env);
int					find_pwd(char **env);
char				**get_path(char **env);
char				**add_last_exec(char **env, char *str);
int					check_oldpwd(char **env);
char				*complete_dir(char *dir, char *str);
int					check_stat(int mode);
char				**destroy_env(char **env);
char				**create_nav(char **av, int ac, int i, t_restart *r);
char				**add_var_env(char **env, char *str);
char				**analyse_rest(int ac, char **av, char **env, t_restart *r);
char				**init(char *line, char **env, t_restart *t);
char				**init_env(char **env);
char				**analyse_line(int ac, char **av, char **env, t_restart *r);
void				multi_error(char *exec, char *file, int er, t_restart *r);
char				**cpy(char **env);
void				test_command(char *file, t_restart *r);
void				display_prompt(char **env);

#endif
