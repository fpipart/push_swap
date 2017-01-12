/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:07:45 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/12 19:47:33 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(void)
{
	ft_putendl_fd("error", 2);
}

char	**fill_with_strsplit(char **argv, int *i)
{
	char **tab;

	tab = ft_strsplit(argv[1], ' ');
	*i = ft_wordcount(argv[1], ' ') - 1; 
	if (*i == 0 && ft_strequ("-v", tab[0]))
		return (NULL);
	return (tab);
}

t_stack	*fill_tab(int argc, char **argv, t_disp *d)
{
	t_stack	*a;
	char	*error;
	int		i;
	int		x;

	a = NULL;
	i = argc - 1;
	if (argc == 2)
		argv = fill_with_strsplit(argv, &i);
	x = 0;
	while ((i > 0 || (i >= 0 && argc == 2)) && argv)
	{
		if (((i == 1 && argc > 2) || i == 0) && ft_strequ(argv[i], "-v"))
			d->verbose = 1;
		else if (!check_doublons(&x, ft_atoi_checker(argv[i], &error), a))
			return (NULL);
		else
			ps_addelem(&a, x);
		if (ft_strequ(error, "error") == 1 && !ft_strequ(argv[i], "-v"))
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
