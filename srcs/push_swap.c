/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:57:43 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/10 12:35:35 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		push_swap(t_stack *a, t_stack *b, int size)
{
	t_disp d;

	d.size_a = stack_size(&a);
	d.phase = 1;
	selection_sort(&a, &b, d);
	//print_stack(a);
	return (0);
}


int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc > 1)
		if (!(a = fill_tab(argc, argv)))
			ps_error();
	if (a)
	{
		push_swap(a, b, argc - 1);
	}
	return (0);
}
