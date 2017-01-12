/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:30:44 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/12 19:06:39 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_atoi_checker(char *str, char **error)
{
	int i;
	int sgn;
	int res;

	res = 0;
	i = 0;
	sgn = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sgn = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	if (!str[i])
		*error = NULL;
	else
		*error = "error";
	return (res * sgn);
}
