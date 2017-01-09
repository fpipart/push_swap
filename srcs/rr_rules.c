/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:57:56 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/09 18:37:15 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	(*stack) = (*stack)->prev;
}

int		rra(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("rra");
	reverse_rotate(a);
	return (1);
}

int		rrb(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("rrb");
	reverse_rotate(b);
	return (1);
}

int		rrr(t_stack **a, t_stack **b, t_disp d)
{
	if (d.print)
		ft_putendl("rrr");
	reverse_rotate(a);
	reverse_rotate(b);
	return (1);
}
