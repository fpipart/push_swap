/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:11:05 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/04 18:24:42 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_rules		*rules(void)
{
	t_rules conv[11];

	conv[0] = (t_rules){"sa", &sa};
	conv[1] = (t_rules){"sb", &sb};
	conv[2] = (t_rules){"ss", &ss};
	conv[3] = (t_rules){"pa", &pa};
	conv[4] = (t_rules){"pb", &pb};
	conv[5] = (t_rules){"ra", &ra};
	conv[6] = (t_rules){"rb", &rb};
	conv[7] = (t_rules){"rr", &rr};
	conv[8] = (t_rules){"rra", &rra};
	conv[9] = (t_rules){"rrb", &rrb};
	conv[10] = (t_rules){"rrr", &rrr};
	return (conv[11]);
}
