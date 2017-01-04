/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:47:22 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/11 16:36:29 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pow(int x, int y)
{
	int a;

	a = 1;
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	while (y--)
		a = a * x;
	return (a);
}
