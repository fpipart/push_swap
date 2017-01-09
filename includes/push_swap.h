/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:49:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/09 18:45:11 by fpipart          ###   ########.fr       */
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
	int				(*f)(t_stack **a, t_stack **b, char *str);
}					t_rules;

typedef struct		s_disp
{
	int				print;
	int				verbose;
	int				size_a;
	int				phase;
}					t_disp;

int					push_swap(t_stack *a, t_stack *b, int size);
int					min_position(t_stack *a);
int					selection_sort(t_stack **a, t_stack **b, t_disp d);


int					check_doublons(int *x, int neww, t_stack *a);
t_stack				*fill_tab(int argc, char **argv);

int					ft_atoi_checker(char *str, char **error);
void				rules(t_rules **conv);

t_stack				*ps_firstelem(int data);
int					ps_addelem(t_stack **stack, int data);
int					stack_size(t_stack **stack);
void				print_stack(t_stack *stack);
int					ps_is_sort(t_stack *a);

void				ps_error(void);

void				swap(t_stack **stack);
int					sa(t_stack **a, t_stack **b, t_disp d);
int					sb(t_stack **a, t_stack **b, t_disp d);
int					ss(t_stack **a, t_stack **b, t_disp d);

void				push(t_stack **s1, t_stack **s2);
int					pa(t_stack **a, t_stack **b, t_disp d);
int					pb(t_stack **a, t_stack **b, t_disp d);

void				rotate(t_stack **stack);
int					ra(t_stack **a, t_stack **b, t_disp d);
int					rb(t_stack **a, t_stack **b, t_disp d);
int					rr(t_stack **a, t_stack **b, t_disp d);

void				reverse_rotate(t_stack **stack);
int					rra(t_stack **a, t_stack **b, t_disp d);
int					rrb(t_stack **a, t_stack **b, t_disp d);
int					rrr(t_stack **a, t_stack **b, t_disp d);

#endif
