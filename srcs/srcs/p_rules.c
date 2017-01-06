/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:29:16 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/06 17:33:55 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **s1, t_stack **s2)
{
	t_stack *tmp;

	tmp = NULL;
	if (s1)
	{
		(*s1)->next->prev = (*s1)->prev;
		(*s1)->prev->next = (*s1)->next;
		if (*s1 != (*s1)->next)
			tmp = (*s1)->next;
		if (*s2)
		{
			(*s1)->prev = (*s2)->prev;
			(*s2)->prev->next = (*s1);
			(*s2)->prev = (*s1);
			(*s1)->next = (*s2);
			*s2 = *s1;
			*s1 = tmp;
		}
		else if (!*s2)
		{
			(*s2) = (*s1);
			(*s2)->prev = (*s2);
			(*s2)->next = (*s2);
		}
		(*s1) = tmp;
	}
}

int		pa(t_stack **a, t_stack **b)
{
	push(b, a);
	return (1);
}

int		pb(t_stack **a, t_stack **b)
{
	push(a, b);
	return (1);
}
