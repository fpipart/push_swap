/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_selection_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:14:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/12 16:39:31 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_next(t_stack **a, t_stack **b, t_disp *d)
{
	if (max_position(*b) <= (*d).size_b / 2 && max_position(*b) != 0)
	{
		while (max_position(*b) != 0)
			rb(a, b, *d);
	}
	while (max_position(*b) != 0)
		rrb(a, b, *d);
	pa(a, b, *d);
	d->size_b--;
}

void	first_sort(t_stack **a, t_stack **b, t_disp *d)
{
	int mins;

	mins = find_segment(*a, d->size_a / 10, *d);
	if (closest_min_pos_next(*a, mins) <= closest_min_pos_prev(*a, mins))
	{
		while (closest_min_pos_next(*a, mins) != 0)
			ra(a, b, *d);
	}
	else if (closest_min_pos_next(*a, mins) > closest_min_pos_prev(*a, mins))
	{
		while (closest_min_pos_next(*a, mins) != 0)
			rra(a, b, *d);
	}
	pb(a, b, *d);
	d->size_b++;
	d->size_a--;
}

int		seg_selection_sort(t_stack **a, t_stack **b, t_disp d)
{
	while (d.phase != 2 || *b)
	{
		if (d.phase == 2)
			push_next(a, b, &d);
		else if (ps_is_sort(*a) && min_value(*a) > max_value(*b))
			d.phase = 2;
		else
			first_sort(a, b, &d);
	}
	return (1);
}
