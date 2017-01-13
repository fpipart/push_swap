/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:31:16 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/13 12:36:27 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	int tmp;

	if (stack && (*stack)->next && (*stack) != (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
}

int		sa(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("sa");
	if ((*a) && (*a)->next && (*a) != (*a)->next)
	{
		swap(a);
		if (d.verbose)
			print_stack_state(*a, *b, d);
		return (1);
	}
	return (0);
}

int		sb(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("sb");
	if ((*b) && (*b)->next && (*b) != (*b)->next)
	{
		swap(b);
		if (d.verbose)
			print_stack_state(*a, *b, d);
		return (1);
	}
	return (0);
}

int		ss(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("ss");
	d.print = 0;
	if ((sa(a, b, d) + sb(a, b, d)) == 2)
	{
		if (d.verbose)
			print_stack_state(*a, *b, d);
		return (1);
	}
	return (0);
}
