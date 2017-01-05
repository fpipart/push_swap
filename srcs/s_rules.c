/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:31:16 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/05 14:47:29 by fpipart          ###   ########.fr       */
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
		(*stack)->next->data =  tmp;
	}
}

int		sa(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*a) != (*a)->next)
	{
		swap(a);
		return (1);
	}
	else
		return (0);
}

int		sb(t_stack **a, t_stack **b)
{
	if ((*b) && (*b)->next && (*b) != (*b)->next)
	{
		swap(b);
		return (1);
	}
	else
		return (0);
}
;
int		ss(t_stack **a, t_stack **b)
{
	if ((sa(a, b) + sb(a, b)) == 2)
}
