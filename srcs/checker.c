/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:03:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/09 17:15:35 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	call_rule(char *rule, t_stack **a, t_stack **b, t_rules op[11])
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(op[i].s, rule))
		{
			if (!op[i].f(a, b))
				return (0);
			ft_putendl("Stack a :");
			print_stack(*a);
			ft_putendl("Stack b :");
			print_stack(*b);
			return (1);
			return (op[i].f(a, b));
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
		if (ft_strequ(line, ""))
			break ;
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
			ps_error();
	if (a)
	{
/*		printf("%5d%5d%5d%5d\n", a->data, a->next->data, a->next->next->data, 
				stack_size(&a));
*/		//print_stack(a);
		result = extract_rules(a, b);
		if (result == -1)
			ps_error();
	}
	return (0);
}
