/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:07:45 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/10 12:35:33 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(void)
{
	ft_putendl_fd("error", 2);
}

char	**fill_with_strsplit(char **argv, int argc)
{
	char **tab;

	tab = ft_strsplit(argv[1], ' ');
	
}

t_stack	*fill_tab(int argc, char **argv)
{
	t_stack	*a;
	char	*error;
	int		i;
	int		x;

	if (argc == 2)
		argv = fill_with_strsplit(argv, argc);
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

void	print_stack_state(t_stack *a, t_stack *b, t_disp d)
{
	ft_putendl("  -------------");
	ft_putstr("Stack a :");
	print_stack(a);
	ft_putstr("Stack b :");
	print_stack(b);
	ft_putendl("  -------------");
}
