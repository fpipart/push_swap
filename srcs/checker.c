/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:03:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/13 11:06:29 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	call_rule(char *rule, t_stack **a, t_stack **b, t_rules op[11])
{
	int		i;
	t_disp	d;

	d.print = 0;
	d.verbose = 0;
	i = 0;
	while (i < 11)
	{
		if (ft_strequ(op[i].s, rule))
		{
			if (!op[i].f(a, b, d))
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	extract_rules(t_stack *a, t_stack *b)
{
	t_rules	*op;
	char	*line;

	op = (t_rules*)malloc(sizeof(t_rules) * 11);
	rules(&op);
	while (get_next_line(0, &line))
	{
		if (!call_rule(line, &a, &b, op))
			return (-1);
	}
	if (ps_is_sort(a) && !b)
	{
		ft_putendl("OK");
		return (1);
	}
	ft_putendl("KO");
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	t_disp	d;
	char	*line;
	int		result;

	a = NULL;
	b = NULL;
	if (argc > 1)
		if (!(a = fill_tab(argc, argv, &d)))
			ps_error();
	if (a)
	{
		result = extract_rules(a, b);
		if (result == -1)
			ps_error();
	}
	return (0);
}
