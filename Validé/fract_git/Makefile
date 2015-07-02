# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/01/24 07:36:00 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= fractol 

SRC=  main.c julia.c mandel.c tric.c cub_julia.c color.c init_env.c

OBJ= $(SRC:.c=.o)

CC= gcc

CFLAGS= -Wextra -Wall -L/usr/X11/lib -lmlx -lXext -lX11 -Ofast

RM= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ):
	make -C libft/
	@$(CC) $(CFLAGS) -I includes -I /usr/X11/include/X11 -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
