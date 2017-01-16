# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpipart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 13:07:23 by fpipart           #+#    #+#              #
#    Updated: 2017/01/16 11:19:21 by fpipart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES1 = checker.c ft_atoi_checker.c stack_utilities.c rules.c		\
		s_rules.c p_rules.c r_rules.c rr_rules.c utilities.c
FILES2 = push_swap.c selection_sort.c ft_atoi_checker.c				\
		stack_utilities.c rules.c s_rules.c p_rules.c r_rules.c		\
		rr_rules.c utilities.c utilities_bis.c seg_selection_sort.c	\
		utilities_ters.c

SRC_PATH = ./srcs/
CFILES1 = $(FILES1:%=./srcs/%)
CFILES2 = $(FILES2:%=./srcs/%)

OBJ_PATH = ./obj/
OBJ_FILE_CK = $(FILES1:%.c=%.o)
OBJ_CK = $(OBJ_FILE_CK:%=$(OBJ_PATH)%)

OBJ_FILE_PS = $(FILES2:%.c=%.o)
OBJ_PS = $(OBJ_FILE_PS:%=$(OBJ_PATH)%)

NAME_CK = checker
NAME_PS = push_swap

LIB_PATH = ./libft/
LIB = libft.a

FLAGS = -Wextra -Werror -Wall

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./includes/push_swap.h
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAG) -o $@ -c $<
	
all: $(NAME_CK) $(NAME_PS)

$(NAME_CK): $(LIB_PATH)$(LIB) $(OBJ_CK) 
	gcc -L ./libft/ -lft -o $(NAME_CK) $(OBJ_CK)

$(NAME_PS): $(LIB_PATH)$(LIB) $(OBJ_PS)
	gcc -L ./libft/ -lft -o $(NAME_PS) $(OBJ_PS)

$(LIB_PATH)$(LIB):
	make -C $(LIB_PATH) 

clean:
	/bin/rm -rf $(OBJ_PATH)
	make -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME_CK)
	/bin/rm -f $(NAME_PS)
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
