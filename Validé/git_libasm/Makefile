# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/09 18:30:02 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= libfts.a

SRC= ft_isascii.s \
	 ft_isdigit.s \
	 ft_isalpha.s \
	 ft_isalnum.s \
	 ft_isprint.s \
	 ft_islower.s \
	 ft_tolower.s \
	 ft_isupper.s \
	 ft_toupper.s \
	 ft_bzero.s \
	 ft_strlen.s \
	 ft_memset.s \
	 ft_memcpy.s \
	 ft_strdup.s \
	 ft_strcat.s \
	 ft_puts.s \
	 ft_cat.s \
	 ft_puts_fd.s \
	 ft_isspace.s \
	 ft_strchr.s \
	 ft_strbcmp.s \
	 ft_strncpy.s \
	 ft_strcpy.s \
	 ft_putspace.s \
	 ft_memalloc.s \
	 ft_strnew.s \

OBJDIR= OBJ/

OBJ= $(SRC:%.s=$(OBJDIR)%.o)

CC= ~/.brew/bin/nasm

CFLAGS= -f macho64 -O3

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	gcc -Wall -Wextra -Werror -o test main.c -L . -lfts

$(OBJDIR)%.o:%.s
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $< -o $@


clean:
	@$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) test

re: fclean all
