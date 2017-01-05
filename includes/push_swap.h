/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:49:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/05 12:21:30 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_tab
{
	int				*a;
	int				*b;
	int				size;
}					t_tab;

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_rules
{
	char			*s;
	int				(*f)(t_stack **a, t_stack **b);
}					t_rules;

int					ft_atoi_checker(char *str, char **error);
t_rules				*rules(void);

t_stack				*ps_fisrtelem(int data);
int					ps_addelem(t_stack **stack, int data);
int					stack_size(t_stack **stack);

#endif
