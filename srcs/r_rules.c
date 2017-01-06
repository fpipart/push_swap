/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:38:21 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/06 18:34:02 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	(*stack) =(*stack)->next;
}

int		ra(t_stack **a, t_stack **b)
{
	rotate(a);
	return (1);
}

int		rb(t_stack **a, t_stack **b)
{
	rotate(b);
	return (1);
}

int		rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	return (1);
}
