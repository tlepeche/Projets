# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/02/05 07:16:23 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= wolf3d

SRC=  event.c get_next_line.c main.c raytex.c bg.c wolftex.c \
	  floorcasting.c game_aspect.c door.c draw_title.c \
	  draw_spwall.c sprite.c free_stuff.c
	  

OBJ= $(SRC:.c=.o)

CC= gcc

CFLAGS= -Werror -Wextra -Wall -L/usr/X11/lib -lmlx -lXext -lX11

RM= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ):
	make -C libft/ fclean
	make -C libft/
	$(CC) $(CFLAGS) -I includes -I /usr/X11/include/X11 -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
