/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:43:42 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/12 17:38:51 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		min_value(t_stack *a)
{
	int		min;
	t_stack	*tmp;

	if (a)
	{
		tmp = a->next;
		min = a->data; 
		while (tmp != a)
		{
			if (tmp->data < min)
				min = tmp->data;
			tmp =tmp->next;
		}
		return (min);
	}
	return (0);
}

int		max_value(t_stack *a)
{
	int		max;
	t_stack	*tmp;

	if (a)
	{
		tmp = a->next;
		max = a->data; 
		while (tmp != a)
		{
			if (tmp->data > max)
				max = tmp->data;
			tmp = tmp->next;
		}
		return (max);
	}
	return (0);
}

int		max_position(t_stack *a)
{
	t_stack *tmp;
	int		max;
	int		i;
	int		pos;

	pos = 0;
	i = 1;
	if (a)
	{
		tmp = a->next;
		max = a->data;
		while (tmp != a)
		{
			if (tmp->data > max)
			{
				pos = i;
				max= tmp->data;
			}
			i++;
			tmp = tmp->next;
		}
	}
	return (pos);
}

int		min_position(t_stack *a)
{
	t_stack *tmp;
	int		min;
	int		i;
	int		pos;

	pos = 0;
	i = 1;
	if (a)
	{
		tmp = a->next;
		min = a->data;
		while (tmp != a)
		{
			if (tmp->data < min)
			{
				pos = i;
				min = tmp->data;
			}
			i++;
			tmp = tmp->next;
		}
	}
	return (pos);
}		

void	ps_delstack(t_stack **a)
{
	t_stack *lst1;
	t_stack *lst2;

	lst1 = *a;
	while (lst1 != (*a)->prev)
	{
		lst2 = lst1->next;
		free(lst1);
		lst1 = lst2;
	}
	free((*a)->prev);
	*a = NULL;
}
