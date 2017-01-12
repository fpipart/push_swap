/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_selection_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:14:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/12 13:04:47 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_segment(t_stack *a, int seg, t_disp d)
{
	t_stack	*tmp;
	int		min;
	int		in_seg;

	in_seg = 0;
	if (a)
	{
		min = min_value(a);
		tmp = a->next;
		while (tmp != a)
		{
			if (min + seg >= tmp->data)
				in_seg++;
			if (in_seg >= d.size_a / 10)
			{
	//	printf("min_value = %d, in_seg = %d, seg = %d\n", min, in_seg, seg);
	//	printf("min + seg = %d\n", min + seg);
				return (min + seg);
			}
			tmp = tmp->next;
		}
		return (find_segment(a, seg * 5 + 10, d));
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

int		seg_selection_sort(t_stack **a, t_stack **b, t_disp d, int end)
{
	int mins;

	if (d.verbose)
		print_stack_state(*a, *b, d);
	if (d.phase == 2 && !*b)
		return (1);
	else if (d.phase == 2)
		push_next(a, b, &d);
	else if (ps_is_sort(*a) && min_value(*a) > max_value(*b))
		d.phase = 2;
	else
	{
		mins = find_segment(*a, d.size_a / 10, d);
		if (closest_min_pos_next(*a, mins) == 0)
		{
			pb(a, b, d);
			d.size_b++;
			d.size_a--;
		}
		else if (closest_min_pos_next(*a, mins) <= closest_min_pos_prev(*a, mins))
			ra(a, b, d);
		else if (closest_min_pos_next(*a, mins) > closest_min_pos_prev(*a, mins))
			rra(a, b, d);
	}
	return (seg_selection_sort(a, b, d, end));
	return (0);
}
