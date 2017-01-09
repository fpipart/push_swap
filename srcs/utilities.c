/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:07:45 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/09 17:15:37 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(void)
{
	ft_putendl_fd("error", 2);
}

t_stack	*fill_tab(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*new;
	char	**line;
	char	*error;
	int		i;
	int		x;

	i = argc - 2;
	x = 0;
	a = ps_firstelem(ft_atoi_checker(argv[argc - 1], &error));
	while (i > 0)
	{
		if (!check_doublons(&x, ft_atoi_checker(argv[i], &error), a))
			return (NULL);
		ps_addelem(&a, x);
		if (ft_strequ(error, "error") == 1)
			return (NULL);
		i--;
	}
	return (a);
}

int		check_doublons(int *x, int new, t_stack *a)
{
	t_stack *tmp;

	*x = new;
	if (a)
	{
		if (a->next != a)
			tmp = a->next;
		else
			tmp = a;
		while (a != tmp)
		{
			if (new == tmp->data)
				return (0);
			tmp = tmp->next;
		}
		if (new == tmp->data)
			return (0);
	}
	return (1);
}
