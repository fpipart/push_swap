/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:17:33 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/06 14:37:01 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ps_firstelem(int data)
{
	t_stack	*elem;

	if (!(elem = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (data)
		elem->data = data;
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

int			ps_addelem(t_stack **stack, int data)
{
	t_stack	*new;

	if (*stack)
	{
		if (!(new = (t_stack*)malloc(sizeof(t_stack))))
			return (-1);
		new->next = *stack;
		new->prev = (*stack)->prev;
		new->data = data;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
		*stack = new;
	}
	return (0);
}

int			stack_size(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (*stack)
	{
		i++;
		tmp = (*stack)->next;
		while (tmp != (*stack))
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

void		print_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (stack)
	{
		tmp = stack->next;
		printf("%5d\n", stack->data);
		while (tmp != stack)
		{
			printf("%5d\n", tmp->data);
			tmp = tmp->next;
		}
	}
}
