# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/03/18 16:17:09 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= fdf

SRC=  fdf.c \
	  get_info.c \
	  get_next_line.c \
	  main.c \
	  find_line.c \
	
OBJDIR= OBJ/

OBJ= $(SRC:%.c=$(OBJDIR)%.o)

CC= gcc

CFLAGS= -g -Wextra -Wall -Werror -L/usr/X11/lib -lmlx -lXext -lX11

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft


$(OBJDIR)%.o:%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I includes -I /usr/X11/include/X11 -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
