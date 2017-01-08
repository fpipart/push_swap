/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:03:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/08 15:28:31 by fpipart          ###   ########.fr       */
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
		if (!call_rule(line, &a, &b, op))
			return (-1);
		if (ft_strequ(line, "\n"))
			break ;
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
			ft_putendl_fd("error", 1);
	if (a)
	{
/*		printf("%5d%5d%5d%5d\n", a->data, a->next->data, a->next->next->data, 
				stack_size(&a));
*/		//print_stack(a);
		result = extract_rules(a, b);
		if (result == -1)
			ft_putendl_fd("error (result = -1)", 2);
	}
	return (0);
}
