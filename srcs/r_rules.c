/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:38:21 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/13 11:03:08 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	(*stack) = (*stack)->next;
}

int		ra(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("ra");
	rotate(a);
	if (d.verbose)
		print_stack_state(*a, *b, d);
	return (1);
}

int		rb(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("rb");
	rotate(b);
	if (d.verbose)
		print_stack_state(*a, *b, d);
	return (1);
}

int		rr(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("rr");
	rotate(a);
	rotate(b);
	if (d.verbose)
		print_stack_state(*a, *b, d);
	return (1);
}
