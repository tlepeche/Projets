# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 05:35:05 by sduprey           #+#    #+#              #
#    Updated: 2015/03/01 09:05:58 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC = main.c draw_grid.c fill_grid.c \
	  set_case_size.c game_loop.c \
	  move_down.c move_up.c move_left.c move_right.c \
	  resolver.c check_move.c cpy_grid.c check_change.c \
	  set_window.c launch.c check_power.c record_score.c \
	  free_grid.c option.c resize_grid.c init_grid.c end_game.c

SRCDIR = src/

OBJDIR = obj/

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC = gcc

INC = -I ./inc

LIB = -L libft -lft

CFLAGS = -Wall -Werror -Wextra -lncurses

RM = rm -rf

all: lft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB) $^
	@echo ""
	@echo "#######################################################"
	@echo "#####   Binary compiled successfully:" $(NAME) "  #####"
	@echo "#######################################################"
	@echo ""

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo $(CC) -c $(CFLAGS) $(INC) $<

lft:
	@make -C libft

clean:
	@$(RM) $(OBJDIR)
	@echo "##### Remove objects #####"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) score.txt
	@make -C libft fclean
	@echo "##### Remove" $(NAME) "#####"

re: fclean all

norm:
	@norminette **/*.[ch]

ex: re
	make clean
	./$(NAME)
