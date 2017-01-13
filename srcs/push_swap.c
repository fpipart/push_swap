/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:57:43 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/13 11:07:28 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push_swap(t_stack *a, t_stack *b, t_disp d)
{
	int seg_min;

	d.size_a = stack_size(&a);
	d.size_b = 0;
	d.phase = 1;
	d.print = 1;
	if (d.size_a <= 30)
		selection_sort(&a, &b, d);
	else
		seg_selection_sort(&a, &b, d);
	ps_delstack(&a);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_disp	d;

	a = NULL;
	b = NULL;
	if (argc > 1)
		if (!(a = fill_tab(argc, argv, &d)))
			ps_error();
	if (a)
		push_swap(a, b, d);
	return (0);
}
