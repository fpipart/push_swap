/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:03:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/04 18:48:09 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/* Verifier que tous les caracteres sont des + ou - au depart puis nombre */
static int	*fill_tab(int argc, char **argv)
{
	char	**line;
	char	*error;
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * argc)))
		return (NULL);
	ft_bzero(tab, sizeof(int) * argc);
	while (i < argc - 1)
	{
		tab[i] = ft_atoi_checker(argv[i + 1], &error);
		if (ft_strequ(error, "error") == 1)
			return (NULL);
		i++;
	}
	return (tab);
}

static int	call_rule(char *rule, t_tab *tab, t_rules op[11])
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(op[i].s, rule))
			return (op[i].f(tab->a, tab->b));
		i++;
	}
	return (0);
}

static int	extract_rules(t_tab tab)
{
	t_rules	*op;
	char	**line;

	op = (t_rules*)malloc(sizeof(t_rules) * 11);
	op = rules();
	if (!(tab.b = (int*)malloc(sizeof(int) * tab.size)))
		return (-1);
	while (get_next_line(0, line))
	{
		if (!call_rule(*line, &tab, op))
			return (-1);
	}
	if (ft_is_sort(tab.a, tab.size))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_tab	tab;
	int		result;

	tab.size = argc - 1;
	tab.a = NULL;
	tab.b = NULL;
	if (argc > 1)
		if (!(tab.a = fill_tab(argc, argv)))
			ft_putstr("error");
	if (tab.a)
	{
		printf("%5d%5d%5d", tab.a[0], tab.a[1], tab.a[2]);
		result = extract_rules(tab);
		if (result == -1)
			ft_putstr("error");
	}
	return (0);
}
