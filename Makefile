# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpipart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 13:07:23 by fpipart           #+#    #+#              #
#    Updated: 2017/01/05 12:51:04 by fpipart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES1 = checker.c ft_atoi_checker.c stack_utilities.c #rules.c

FILES2 =

CFILES1 = $(FILES1:%=./srcs/%)

OBJ1 = $(FILES1:%.c=%.o)

CFILES2 = $(FILES2:%=./srcs/%)

OBJ2 = $(FILES2:%.c=%.o)

FLAGS = -Wextra -Werror -Wall

NAME1 = checker

NAME2 = push_swap

#Attention fonctionnement attendu : recompilation uniquement des fichier modif
all: $(NAME1)

$(NAME1):
	make -C ./libft/
	gcc $(FLAG) -c $(CFILES1)
	gcc -L ./libft/ -lft -o $(NAME1) $(OBJ1)

clean:
	/bin/rm -f $(OBJ1)
	make -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME1)
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
