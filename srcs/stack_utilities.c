/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:17:33 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/11 12:49:24 by fpipart          ###   ########.fr       */
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
	else
		*stack = ps_firstelem(data);
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
		ft_printf("%5d", stack->data);
		while (tmp != stack)
		{
			ft_printf(" %d", tmp->data);
			tmp = tmp->next;
		}
	}
	ft_printf("\n");
}

int			ps_is_sort(t_stack *a)
{
	t_stack *tmp;

	if (a)
	{
		tmp = a;
		while (tmp->next != a)
		{
			if (tmp->next->data <= tmp->data)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
