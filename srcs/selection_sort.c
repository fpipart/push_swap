/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:34:13 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/13 12:26:24 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sort_three_1(t_stack **a, t_stack **b, t_disp d, int a3)
{
	if ((*a)->data < a3 && (*a)->next->data > a3)
	{
		rra(a, b, d);
		sa(a, b, d);
	}
	else if (a3 > (*a)->next->data)
		sa(a, b, d);
	else
		rra(a, b, d);
	return (1);
}

static int	sort_three_2(t_stack **a, t_stack **b, t_disp d, int a3)
{
	if ((*a)->data < a3)
		sa(a, b, d);
	else if ((*a)->next->data > a3)
	{
		ra(a, b, d);
		sa(a, b, d);
	}
	else
		ra(a, b, d);
	return (1);
}


int			sort_three(t_stack **a, t_stack **b, t_disp d)
{
	int a3;

	a3 = (*a)->next->next->data;
	if ((*a)->data < (*a)->next->data)
		sort_three_1(a, b, d, a3);
	else if ((*a)->data > (*a)->next->data)
		sort_three_2(a, b, d, a3);
	return (1);
}

static void	next_push(t_stack **a, t_stack **b, t_disp *d)
{
	if (min_position(*a) <= d->size_a / 2 && min_position(*a) != 0)
		while (min_position(*a) != 0)
			ra(a, b, *d);
	while (min_position(*a) != 0)
		rra(a, b, *d);
	if (min_position(*a) == 0 && !ps_is_sort(*a))
	{
		d->size_a--;
		pb(a, b, *d);
	}
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
	{
		sort_three(a, b, d);
		d.phase = 2;
	}
	else if (d.size_a == 2)
		sa(a, b, d);
	else if (d.phase == 1)
		next_push(a, b, &d);
	selection_sort(a, b, d);
	return (0);
}
