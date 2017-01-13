/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:49:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/13 11:19:22 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_disp
{
	int				print;
	int				verbose;
	int				size_a;
	int				size_b;
	int				phase;
}					t_disp;

typedef struct		s_rules
{
	char			*s;
	int				(*f)(t_stack **a, t_stack **b, t_disp d);
}					t_rules;

int					selection_sort(t_stack **a, t_stack **b, t_disp d);
int					seg_selection_sort(t_stack **a, t_stack **b, t_disp d);

/*
 **		stack_utilities.c
*/

t_stack				*ps_firstelem(int data);
int					ps_addelem(t_stack **stack, int data);
int					stack_size(t_stack **stack);
void				print_stack(t_stack *stack);
int					ps_is_sort(t_stack *a);

/*
 **		utilities.c
*/

void				ps_error(void);
char				**fill_with_strsplit(char **argv, int *i);
void				print_stack_state(t_stack *a, t_stack *b, t_disp d);
int					check_doublons(int *x, int neww, t_stack *a);
t_stack				*fill_tab(int argc, char **argv, t_disp *d);

/*
 **		utilities_bis.c
*/

int					min_value(t_stack *a);
int					min_position(t_stack *a);
int					max_value(t_stack *a);
int					max_position(t_stack *a);
void				ps_delstack(t_stack **a);

/*
 **		utilities_ters.c
*/

int					find_segment(t_stack *a, int seg, t_disp d);
int					closest_min_pos_next(t_stack *a, int mins);
int					closest_min_pos_prev(t_stack *a, int mins);

int					ft_atoi_checker(char *str, char **error);

void				rules(t_rules **conv);

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
