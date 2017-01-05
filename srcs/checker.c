/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:03:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/05 14:21:04 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/* Verifier que tous les caracteres sont des + ou - au depart puis nombre */
static t_stack	*fill_tab(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*new;
	char	**line;
	char	*error;
	int		i;

	i = 1;
	a = ps_fisrtelem(ft_atoi_checker(argv[1], &error));
	while (i < argc - 1)
	{
		ps_addelem(&a, ft_atoi_checker(argv[i + 1], &error));
		if (ft_strequ(error, "error") == 1)
			return (NULL);
		i++;
	}
	return (a);
}

static int	call_rule(char *rule, t_stack **a, t_stack **b, t_rules op[11])
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(op[i].s, rule))
			return (op[i].f(a, b));
		i++;
	}
	return (0);
}

static int	extract_rules(t_stack *a, t_stack *b)
{
	t_rules	*op;
	char	*line;

	op = (t_rules*)malloc(sizeof(t_rules) * 11);
//	op = rules();
	while (get_next_line(0, &line))
	{
		if (!call_rule(line, &a, &b, op))
			return (-1);
	}
//	if (ft_is_sort(tab.a, tab.size))
//		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	*line;
	int		result;

	a = NULL;
	b = NULL;
	if (argc > 1)
		if (!(a = fill_tab(argc, argv)))
			ft_putstr("error");
	if (a)
	{
		printf("%5d%5d%5d%5d\n", a->data, a->next->data, a->next->next->data, 
				stack_size(&a));
		result = extract_rules(a, b);
		if (result == -1)
			ft_putstr("error");
	}
	return (0);
}
