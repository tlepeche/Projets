# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/04/03 18:59:05 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= push_swap 

SRC= main.c \
	 swap.c \
	 push.c \
	 rotate.c \
	 r_rotate.c \
	 verif_arg.c \
	 check_list.c \
	 resolver.c \
	 print_details.c \
	 print_str.c \
	 pile_tools.c \
	 move_tools.c \
	 status_tools.c \
	 option.c \
	 choose_resolver.c \
	 insert_sort.c \
	 insert_sort_add.c \

OBJDIR= OBJ/

OBJ= $(SRC:%.c=$(OBJDIR)%.o)

CC= gcc

CFLAGS= -Wextra -Wall -Werror -Ofast

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJDIR)%.o : %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
