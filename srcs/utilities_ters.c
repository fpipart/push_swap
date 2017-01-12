/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_ters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:31:24 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/12 16:46:44 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_segment(t_stack *a, int seg, t_disp d)
{
	t_stack	*tmp;
	int		min;
	int		in_seg;

	while (a)
	{
		min = min_value(a);
		tmp = a->next;
		in_seg = 0;
		while (tmp != a)
		{
			if (min + seg >= tmp->data)
				in_seg++;
			if (in_seg >= d.size_a / 10)
				return (min + seg);
			tmp = tmp->next;
		}
		seg = seg + 10;
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
	if		(a)
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
