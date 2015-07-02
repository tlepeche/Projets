# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/03/23 07:21:03 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= ft_minishell1 

SRC=  main.c \
	  get_next_line.c \
	  setenv.c \
	  cd.c \
	  env.c \
	  unsetenv.c \
	  executable.c \
	  file_exec.c \
	  create_env.c \
	  test_directory.c \
	  change_av.c \
	  change_cd.c \
	  find_path.c \
	  add_last_exec.c \
	  env_stuff.c \
	  init_main.c \
	  test_command.c \
	  prompt.c \

OBJDIR= OBJ/

OBJ= $(SRC:%.c=$(OBJDIR)%.o)

CC= gcc

CFLAGS= -Wextra -Wall -Werror

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft


$(OBJDIR)%.o:%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
