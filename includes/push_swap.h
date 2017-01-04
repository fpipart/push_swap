/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:49:01 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/04 18:39:07 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_rules
{
	char			*s;
	int				(*f)(int **tab_a, int **tab_b);
}					t_rules;

typedef struct		s_tab
{
	int				*a;
	int				*b;
	int				size;
}					t_tab;

int					ft_atoi_checker(char *str, char **error);
t_rules				*rules(void);

#endif
