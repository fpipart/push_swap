/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_selection_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:14:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/11 19:05:41 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_segment(t_stack *a, int seg, int in_seg)
{
	t_stack	*tmp;
	int		min;

	min = min_value(a);
	if (a)
	{
		tmp = a->next;
		
		while (tmp != a)
		{
			if (min + seg >= tmp->data)
				in_seg++;
			if (in_seg >= seg)
				return (min + seg);
		}
		find_segment(a, seg * 2, in_seg);
	}
	return (0);
}

int		closest_min_pos_next(t_stack *a, int mins)
{
	t_stack *tmp;
	int		i;

	i = 1;
	if (a)
	{
		if (a->data <= mins)
			return (0);
		tmp = a->next;
		while (tmp != a)
		{
			if (tmp->data <= mins)
				return (i);
			i++;
			tmp = tmp->next;
		}
		//printf("min = %d, pos = %d\n", min, pos);
	}
	return (-1);
}

int		closest_min_pos_prev(t_stack *a, int mins)
{
	t_stack *tmp;
	int		i;

	i = 1;
	if (a)
	{
		if (a->data <= mins)
			return (0);
		tmp = a->prev;
		while (tmp != a)
		{
			if (tmp->data <= mins)
				return (i);
			i++;
			tmp = tmp->prev;
		}
		//printf("min = %d, pos = %d\n", min, pos);
	}
	return (-1);
}

void	push_next(t_stack **a, t_stack **b, t_disp *d)
{
	if (max_position(*b) == 0)
	{
		pa(a, b, *d);
		d->size_b--;
	}
	else
		max_position(*b) <= (*d).size_b / 2 ? rb(a, b, *d) : rrb(a, b, *d);
}

int		seg_selection_sort(t_stack **a, t_stack **b, t_disp d)
{
	int	mins;

	mins = find_segment(*a, d.size_a / 10, d.size_a / 10);
	if (d.verbose)
		print_stack_state(*a, *b, d);
	if (d.phase == 2 && !*b)
		return (1);
	else if (d.phase == 2)
		push_next(a, b, &d);
	else if (ps_is_sort(*a) && min_value(*a) > max_value(*b))
		d.phase = 2;
	else if (closest_min_pos_next(*a, mins) == 0)
	{
		pb(a, b, d);
		d.size_b++;
	}
	else if (closest_min_pos_next(*a, mins) <= closest_min_pos_prev(*a, mins))
		ra(a, b, d);
	else if (closest_min_pos_next(*a, mins) > closest_min_pos_prev(*a, mins))
		rra(a, b, d);
	seg_selection_sort(a, b, d);
	return (0);
}
