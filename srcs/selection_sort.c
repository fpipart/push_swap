/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:34:13 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/11 18:08:49 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			sort_three(t_stack **a, t_stack **b, t_disp d)
{
	int a3;

	a3 = (*a)->next->next->data;
	if ((*a)->data < (*a)->next->data)
	{
		rra(a, b, d);
		if ((*a)->data < a3 && (*a)->next->data > a3)
			sa(a, b, d);
	}
	if ((*a)->data > (*a)->next->data)
	{
		if ((*a)->data < a3)
			sa(a, b, d);
		else
			ra(a, b, d);
		if ((*a)->next->data > a3)
			ra(a, b, d);
	}
	return (1);
}

int			selection_sort(t_stack **a, t_stack **b, t_disp d)
{
	if (d.phase == 2 && !(*b))
		return (1);
	else if (d.phase == 2 && *b)
		pa(a, b, d);
	else if (ps_is_sort(*a))
		d.phase = 2;
	else if (d.size_a == 3)
		sort_three(a, b, d);
	else if (d.phase == 1)
	{
		if (min_position(*a) == 0)
		{
			d.size_a--;
			pb(a, b, d);
		}
		else
			min_position(*a) <= d.size_a / 2 ? ra(a, b, d) : rra(a, b, d);
	}
	if (d.verbose)
		print_stack_state(*a, *b, d);
	selection_sort(a, b, d);
	return (0);
}
