# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/03/22 03:32:10 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= ft_select 

SRC=  main.c \
	  print_list.c \
	  move.c \
	  list_tools.c \
	  print_selected.c \
	  delete.c \
	  check_key.c \
	  term_tools.c \
	  loop_tools.c \
	
OBJDIR= OBJ/

OBJ= $(SRC:%.c=$(OBJDIR)%.o)

CC= gcc

CFLAGS= -Wextra -Wall -Werror

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -lncurses -o $(NAME) $(OBJ) -L libft/ -lft


$(OBJDIR)%.o:%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
