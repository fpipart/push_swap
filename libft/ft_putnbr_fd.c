/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:03 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/09 17:35:48 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;
	char			sgn;

	sgn = 1;
	n1 = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = -n;
	}
	if (n1 / 10 != 0)
		ft_putnbr_fd(n1 / 10, fd);
	ft_putchar_fd((n1 % 10) + '0', fd);
}
